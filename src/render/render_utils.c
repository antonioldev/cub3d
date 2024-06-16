/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:48:28 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 12:57:27 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Determines the quadrant of the angle on the unit circle, return 1 if in range
if c == x, direction is right, if c == y direction is down*/
int	unit_circle(float angl, char c)
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

/*Set the distance and size of walls based on the intersection*/
void	set_right_intersection(t_cub3d *cub3d, t_intersect inter, int flag)
{
	cub3d->ray.distance = inter.inter;
	cub3d->ray.wall_w = fmod(inter.offset, TILE_SIZE);
	cub3d->ray.flag = flag;
	cub3d->ray.type = inter.type;
	cub3d->ray.index = inter.index;
}

/*Adjust the intersection and step values based on the angle and if is
horizontal or vertical intersection*/
int	intersection_check(float angl, float *inter,
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
		if (!(angl > M_PI / 2 && angl < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

/*Normalize the angle do be in range 0-360degree to avoid the fish eye effect*/
float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle >= 2 * M_PI)
		angle -= (2 * M_PI);
	return (angle);
}

/*Return the index of the door that has been found during raycasting*/
int	find_index_door(t_cub3d *cub3d, int pos_y, int pos_x)
{
	char	door;
	int		count;
	int		x;
	int		y;

	door = 'D';
	count = 0;
	y = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (y == pos_y && x == pos_x)
				return (count);
			if (cub3d->map.map[y][x] == door
				|| cub3d->map.map[y][x] == door + 32)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
