/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_addrs_img_doors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:38:25 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 15:29:56 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Determines the quadrant of the angle on the unit circle, return 1 if in range
if c == x, direction is right, if c == y direction is down*/
static void	draw_map(t_cub3d *cub3d, int ray, int t_pixel, int b_pixel)
{
	int				i;
	int				y;
	unsigned int	color;
	t_texture		texture;

	i = -1;
	texture = cub3d->doors[cub3d->ray.index].texture;
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
void	render_door(t_cub3d *cub3d, int ray)
{
	float	wall_h;
	float	b_pixel;
	float	t_pixel;

	wall_h = cub3d->ray.distance_scale / cub3d->ray.distance;
	b_pixel = (HEIGHT >> 1) + (wall_h / 2);
	t_pixel = (HEIGHT >> 1) - (wall_h / 2);
	draw_map(cub3d, ray, t_pixel, b_pixel);
	
}
