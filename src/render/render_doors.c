/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:21:48 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 15:43:29 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Calculate the distance from player and find the right texture to use*/
void	check_doors(t_cub3d *cub3d, int i)
{
	t_door	*door;
	int		index;

	while (++i < cub3d->num_doors)
	{
		door = &cub3d->doors[i];
		door->d_x = door->p_x - cub3d->p.p_x;
		door->d_y = door->p_y - cub3d->p.p_y;
		door->distance_to_player = sqrt(pow(door->d_x, 2) + pow(door->d_y, 2));
		if (door->distance_to_player > 252)
			door->texture = cub3d->bonus_door[8];
		else
		{
			index = (int)(door->distance_to_player - 100) / 20;
			if (index < 0)
				index = 0;
			door->texture = cub3d->bonus_door[index];
		}
	}
}

/*Check if the coordinates x and y intersect with a door
 return 0 if a door was hit or coordinates are out of bounds*/
static int	is_hit(float x, float y, t_cub3d *cub3d,
	t_intersect *intersect)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if (y_m >= cub3d->map.height || x_m >= cub3d->map.width
		|| y_m < 0 || x_m < 0)
		return (0);
	if (cub3d->map.map[y_m][x_m] == '1')
	{
		intersect->type = cub3d->map.map[y_m][x_m];
		return (0);
	}
	else if (cub3d->map.map[y_m][x_m] == 'D'
		|| cub3d->map.map[y_m][x_m] == 'd')
	{
		intersect->index = find_index_door(cub3d, y_m, x_m);
		intersect->type = cub3d->map.map[y_m][x_m];
		return (0);
	}
	return (1);
}

/*Find the distance with the nearest vertical wall intersection by
 - Calculate the initial vertical intersection and step values
 - Adjust the values based on the angledouble
 - Looping until a wall is hit*/
static void	find_v_inter_door(t_cub3d *cub3d, float angl,
	t_intersect *intersect)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(cub3d->p.p_x / TILE_SIZE) * TILE_SIZE;
	pixel = intersection_check(angl, &v_x, &x_step, 0);
	v_y = cub3d->p.p_y + (v_x - cub3d->p.p_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0)
		|| (!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (is_hit(v_x - pixel, v_y, cub3d, intersect))
	{
		v_x += x_step;
		v_y += y_step;
	}
	if (intersect->type == 'd')
		intersect->type = '1';
	intersect->inter = sqrt(pow(v_x - cub3d->p.p_x, 2) + 
			pow(v_y - cub3d->p.p_y, 2));
	intersect->offset = fabs(v_y);
}

/*Find the distance with the nearest horizontal wall intersection by
 - Calculate the initial horizontal intersection and step values
 - Adjust the values based on the angle
 - Looping until a wall is hit*/
static void	find_h_inter_door(t_cub3d *cub3d, float angl,
	t_intersect *intersect)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(cub3d->p.p_y / TILE_SIZE) * TILE_SIZE;
	pixel = intersection_check(angl, &h_y, &y_step, 1);
	h_x = cub3d->p.p_x + (h_y - cub3d->p.p_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0)
		|| (!unit_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	while (is_hit(h_x, h_y - pixel, cub3d, intersect))
	{
		h_x += x_step;
		h_y += y_step;
	}
	if (intersect->type == 'D')
		intersect->type = '1';
	intersect->inter = sqrt(pow(h_x - cub3d->p.p_x, 2) + \
			pow(h_y - cub3d->p.p_y, 2));
	intersect->offset = fabs(h_x);
}

/*Loop each ray of the screen and serch for intersection with doors*/
void	raycasting_door(t_cub3d *cub3d, int ray)
{
	t_intersect	h_inter;
	t_intersect	v_inter;

	cub3d->ray.ray_ngl = cub3d->p.angle - (cub3d->p.fov_rd / 2);
	// cub3d->ray.ray_ngl = nor_angle(cub3d->ray.ray_ngl);
	while (ray < WIDTH)
	{
		find_v_inter_door(cub3d, cub3d->ray.ray_ngl, &v_inter);
		find_h_inter_door(cub3d, cub3d->ray.ray_ngl, &h_inter);
		if (v_inter.type == 'D' && v_inter.inter > 32 && v_inter.inter <= h_inter.inter)
			set_right_intersection(cub3d, v_inter, 0);
		else if (h_inter.type == 'd' && h_inter.inter > 32 && h_inter.inter < v_inter.inter)
			set_right_intersection(cub3d, h_inter, 1);
		else
			cub3d->ray.type = '1';
		if (cub3d->ray.type == 'D' || cub3d->ray.type == 'd')
		{
			cub3d->ray.distance *= cos(cub3d->ray.ray_ngl
					- cub3d->p.angle);
			render_door(cub3d, ray);
		}
		ray++;
		cub3d->ray.ray_ngl += (cub3d->p.fov_rd / WIDTH);
		cub3d->ray.ray_ngl = nor_angle(cub3d->ray.ray_ngl);
	}
}
