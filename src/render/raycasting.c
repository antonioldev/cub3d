/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:04:34 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/05 14:25:31 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Determines the quadrant of the angle on the unit circle, return 1 if in range
if c == x, direction is right, if c == y direction is down*/
static int	unit_circle(float angl, char c)
{
	if (c == 'x')
	{
		if (angl > 0 && angl < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angl > (M_PI / 2) && angl < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

/*Adjust the intersection and step values based on the angle and if is
horizontal or vertical intersection*/
static int	intersection_check(float angl, float *inter,
	float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angl > 0 && angl < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!((angl > (M_PI / 2)) && (angl < ((3 * M_PI) / 2))))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

/*Check if the coordinates x and y intersect with a wall
 return 0 if a wall was hit or coordinates are out of bounds*/
static int	wall_hit(float x, float y, t_cub3d *cub3d)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if (y_m >= cub3d->map.height || x_m >= cub3d->map.width)
		return (0);
	if (cub3d->map.map[y_m] && x_m <= (int)ft_strlen(cub3d->map.map[y_m]))
		if (cub3d->map.map[y_m][x_m] == '1')
			return (0);
	return (1);
}

/*Find the distance with the nearest vertical wall intersection by
 - Calculate the initial vertical intersection and step values
 - Adjust the values based on the angle
 - Looping until a wall is hit*/
void	find_v_inter(t_cub3d *cub3d, float angl, t_intersect *intersect)
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
	while (wall_hit(v_x - pixel, v_y, cub3d))
	{
		v_x += x_step;
		v_y += y_step;
	}
	intersect->inter = sqrt(pow(v_x - cub3d->p.p_x, 2) + \
			pow(v_y - cub3d->p.p_y, 2));
	intersect->offset = v_y;
}

/*Find the distance with the nearest horizontal wall intersection by
 - Calculate the initial horizontal intersection and step values
 - Adjust the values based on the angle
 - Looping until a wall is hit*/
void	find_h_inter(t_cub3d *cub3d, float angl, t_intersect *intersect)
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
	while (wall_hit(h_x, h_y - pixel, cub3d))
	{
		h_x += x_step;
		h_y += y_step;
	}
	intersect->inter = sqrt(pow(h_x - cub3d->p.p_x, 2) + \
			pow(h_y - cub3d->p.p_y, 2));
	intersect->offset = h_x;
}
