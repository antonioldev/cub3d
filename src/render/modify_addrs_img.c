/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_addrs_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:13:06 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 12:00:35 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Assign the proper color to a specific pixel*/
void	draw_pixel(t_cub3d *cub3d, int ray, unsigned int color, int i)
{
	char	*pixel_addr;

	if (color == 0xff000000)
		return ;
	if (i >= 0 && i < HEIGHT)
	{
		pixel_addr = cub3d->game.img.addr + (i * cub3d->game.img.line_length + \
			ray * (cub3d->game.img.bpp / 8));
		if (pixel_addr < cub3d->game.img.addr + cub3d->game.img.line_length * \
				HEIGHT)
			*(unsigned int *)pixel_addr = color;
	}
}

/*Get the right pattern for the walls, in order W E S N*/
static t_texture	get_texture_walls(t_cub3d *cub3d, int flag)
{
	cub3d->ray.ray_ngl = nor_angle(cub3d->ray.ray_ngl);
	if (flag == 0)
	{
		if (cub3d->ray.ray_ngl > M_PI / 2
			&& cub3d->ray.ray_ngl < 3 * (M_PI / 2))
			return (cub3d->textures[WEST]);
		else
			return (cub3d->textures[EAST]);
	}
	else
	{
		if (cub3d->ray.ray_ngl > 0 && cub3d->ray.ray_ngl < M_PI)
			return (cub3d->textures[SOUTH]);
		else
			return (cub3d->textures[NORTH]);
	}
}

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
void	render_enviroment(t_cub3d *cub3d, int ray)
{
	float	wall_h;
	float	b_pixel;
	float	t_pixel;

	wall_h = cub3d->ray.distance_scale / cub3d->ray.distance;
	b_pixel = (HEIGHT >> 1) + (wall_h / 2);
	t_pixel = (HEIGHT >> 1) - (wall_h / 2);
	draw_map(cub3d, ray, t_pixel, b_pixel);
}

/*Get the right color for the walls, in order W E S N
	use with walls without texture*/
// static int	get_color(t_cub3d *cub3d, int flag)
// {
// 	cub3d->ray.ray_ngl = nor_angle(cub3d->ray.ray_ngl);
// 	if (flag == 0)
// 	{
// 		if (cub3d->ray.ray_ngl > M_PI / 2
// 			&& cub3d->ray.ray_ngl < 3 * (M_PI / 2))
// 			return (0xFF6666);
// 		else
// 			return (0xFF0000);
// 	}
// 	else
// 	{
// 		if (cub3d->ray.ray_ngl > 0 && cub3d->ray.ray_ngl < M_PI)
// 			return (0x990000);
// 		else
// 			return (0x660000);
// 	}
// }
