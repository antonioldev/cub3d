/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:48:28 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/13 16:44:44 by alimotta         ###   ########.fr       */
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
	cub3d->ray.wall_w = inter.offset;
	cub3d->ray.flag = flag;
	cub3d->ray.type = inter.type;
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
