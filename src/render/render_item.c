/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:12 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/04 19:25:46 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Normalize the angle do be in range 0-360degree to avoid the fish eye effect*/
float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle >= 2 * M_PI)
		angle -= (2 * M_PI);
	return (angle);
}

/*Calculate the wall height and the top and bottom pixel for the wall*/
void	render_wall(t_cub3d *cub3d, int ray)
{
	double	wall_h;
	double	b_pixel;
	double	t_pixel;

	wall_h = (TILE_SIZE / cub3d->ray.distance) * cub3d->p.distance_to_plane;
	b_pixel = (HEIGHT >> 1) + (wall_h / 2);
	t_pixel = (HEIGHT >> 1) - (wall_h / 2);
	if (b_pixel > HEIGHT)
		b_pixel = HEIGHT;
	if (t_pixel < 0)
		t_pixel = 0;

	// if (cub3d->ray.flag == 0)
        cub3d->ray.wall_x = cub3d->ray.intersect_y;
    // else
    //     cub3d->ray.wall_x = cub3d->ray.intersect_x;
	cub3d->ray.wall_x = fmod(cub3d->ray.wall_x, TILE_SIZE);
	draw_map(cub3d, ray, t_pixel, b_pixel);
}
