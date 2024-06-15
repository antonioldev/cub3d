/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enviroment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:12 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 08:43:13 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Draw the 3d map using its address, each loop draw different parts of the map
respectively cealing, walls, floor*/
static void	draw_map(t_cub3d *cub3d, int ray, int t_pixel, int b_pixel)
{
	int				i;
	int				y;
	unsigned int	color;
	t_texture		texture;

	i = -1;
	texture = get_texture_walls(cub3d, cub3d->ray.flag);
	while (++i < t_pixel)
		draw_pixel(cub3d, ray, cub3d->map.c, i);
	i = t_pixel - 1;
	while (++i < b_pixel)
	{
		y = ((i - t_pixel) * texture.height) / (b_pixel - t_pixel);
		color = get_tex_color(texture, cub3d->ray.wall_w, y);
		draw_pixel(cub3d, ray, color, i);
	}
	i = b_pixel - 1;
	while (++i < HEIGHT)
		draw_pixel(cub3d, ray, cub3d->map.f, i);
}

/*Calculate the wall height and the top and bottom pixel for the wall*/
static void	render_enviroment(t_cub3d *cub3d, int ray)
{
	float	wall_h;
	float	b_pixel;
	float	t_pixel;

	wall_h = cub3d->ray.distance_scale / cub3d->ray.distance;
	b_pixel = (HEIGHT >> 1) + (wall_h / 2);
	t_pixel = (HEIGHT >> 1) - (wall_h / 2);
	draw_map(cub3d, ray, t_pixel, b_pixel);
}

/*Check if the coordinates x and y intersect with a wall
 return 0 if a wall was hit or coordinates are out of bounds*/
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
	return (1);
}

/*Find the distance with the nearest vertical wall intersection by
 - Calculate the initial vertical intersection and step values
 - Adjust the values based on the angledouble
 - Looping until a wall is hit*/
static void	find_v_inter(t_cub3d *cub3d, float angl,
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
	intersect->inter = sqrt(pow(v_x - cub3d->p.p_x, 2) + \
			pow(v_y - cub3d->p.p_y, 2));
	intersect->offset = fabs(v_y);
}

/*Find the distance with the nearest horizontal wall intersection by
 - Calculate the initial horizontal intersection and step values
 - Adjust the values based on the angle
 - Looping until a wall is hit*/
static void	find_h_inter(t_cub3d *cub3d, float angl,
	t_intersect *intersect)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE ;
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
	intersect->inter = sqrt(pow(h_x - cub3d->p.p_x, 2) + \
			pow(h_y - cub3d->p.p_y, 2));
	intersect->offset = fabs(h_x);
}

/*For each ray calculate the vertical and horizontal intersection*/
void	raycasting(t_cub3d *cub3d)
{
	t_intersect	h_inter;
	t_intersect	v_inter;
	int			ray;

	ray = 0;
	cub3d->ray.ray_ngl = cub3d->p.angle - (cub3d->p.fov_rd / 2);
	while (ray < WIDTH)
	{
		find_v_inter(cub3d, cub3d->ray.ray_ngl, &v_inter);
		find_h_inter(cub3d, cub3d->ray.ray_ngl, &h_inter);
		if (v_inter.inter <= h_inter.inter)
			set_right_intersection(cub3d, v_inter, 0);
		else
			set_right_intersection(cub3d, h_inter, 1);
		cub3d->ray.distance *= cos(nor_angle(cub3d->ray.ray_ngl
					- cub3d->p.angle));
		render_enviroment(cub3d, ray);
		ray++;
		cub3d->ray.ray_ngl += (cub3d->p.fov_rd / WIDTH);
	}
}