/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enviroment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:12 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/08 15:44:52 by alimotta         ###   ########.fr       */
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
	texture = get_texture(cub3d, cub3d->ray.flag);
	while (++i < t_pixel)
		draw_pixel(cub3d, ray, 0xFFFFFF, i);//Change cealing color
	i = t_pixel - 1;
	while (++i < b_pixel)
	{
		y = ((i - t_pixel) * texture.height) / (b_pixel - t_pixel);
		color = get_tex_color(texture, cub3d->ray.wall_x, y);
		draw_pixel(cub3d, ray, color, i);
	}
	i = b_pixel - 1;
	while (++i < HEIGHT)
		draw_pixel(cub3d, ray, (0x808080), i);
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

/*Calculate the wall height and the top and bottom pixel for the wall*/
void	render_enviroment(t_cub3d *cub3d, int ray)
{
	double	wall_h;
	double	b_pixel;
	double	t_pixel;

	wall_h = cub3d->ray.distance_scale / cub3d->ray.distance;
	b_pixel = (HEIGHT >> 1) + (wall_h / 2);
	t_pixel = (HEIGHT >> 1) - (wall_h / 2);
	cub3d->ray.wall_x = fmod(cub3d->ray.wall_x, TILE_SIZE);
	draw_map(cub3d, ray, t_pixel, b_pixel);
}
