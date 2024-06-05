/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_addrs_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:13:06 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/05 14:41:23 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Fill the mini map area with black pixels*/
void	clear_mini_map(t_mlx *game)
{
	int		x;
	int		y;
	char	*pixel_addr;
	t_img	*img;

	img = &game->img_minimap;
	y = 0;
	while (y < HEIGHT_MINI)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_addr = (img->addr + y * \
					img->line_length + x * (img->bpp / 8));
			*(unsigned int *)pixel_addr = 0x0;
			x++;
		}
		y++;
	}
}

/*Draw more pixel for each part of the map*/
void	draw_square_minimap(t_mlx *game, int w, int h, int color)
{
	int		i;
	int		j;
	char	*pixel_addr;

	i = 0;
	while (i < PIXEL_MINI)
	{
		j = 0;
		while (j < PIXEL_MINI)
		{
			pixel_addr = game->img_minimap.addr + ((h + i) * \
					game->img_minimap.line_length + (w + j) * \
					(game->img_minimap.bpp / 8));
			if (pixel_addr < game->img_minimap.addr + \
					game->img_minimap.line_length * HEIGHT_MINI)
				*(unsigned int *)pixel_addr = color;
			j++;
		}
		i++;
	}
}

/*Assign the proper color to a specific pixel*/
void	draw_pixel(t_cub3d *cub3d, int ray, int color, int i)
{
	char	*pixel_addr;

	pixel_addr = cub3d->game.img.addr + (i * cub3d->game.img.line_length + \
			ray * (cub3d->game.img.bpp / 8));
	if (pixel_addr < cub3d->game.img.addr + cub3d->game.img.line_length * \
			HEIGHT)
		*(unsigned int *)pixel_addr = color;
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

/*Get the right pattern for the walls, in order W E S N*/
t_texture	get_texture(t_cub3d *cub3d, int flag)
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

/*Assign the proper color to a specific pixel*/
unsigned int	get_texture_color(t_texture texture, int x, int y)
{
	int		offset;
	char	*texture_addr;

	offset = y * texture.line_length + x * (texture.bpp / 8);
	texture_addr = texture.addr + offset;
	return (*(unsigned int *)texture_addr);
}
