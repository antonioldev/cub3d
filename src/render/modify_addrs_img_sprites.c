/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_addrs_img_sprites.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:24:27 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 08:45:15 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Assign the proper color to a specific pixel*/
unsigned int	get_tex_color(t_texture texture, int x, int y)
{
	int		offset;
	char	*texture_addr;

	offset = y * texture.line_length + x * (texture.bpp / 8);
	texture_addr = texture.addr + offset;
	return (*(unsigned int *)texture_addr);
}

/*Check the color of the pixel and return it if not transparent*/
static void	draw_pixel_sprite(t_cub3d *cub3d, unsigned int color, int x, int y)
{
	int	pixel_index;

	if (color == 0xff000000)
		return ;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_index = (y * WIDTH + x) * (cub3d->game.img.bpp / 8);
		*(unsigned int *)(cub3d->game.img.addr + pixel_index) = color;
	}
}

/*Calculate the pixel that needs to be render*/
void	draw_sprite(t_cub3d *cub3d, t_sprite *sprite, int texture_x,
	int texture_y)
{
	int				i;
	int				j;

	i = sprite->l_pixel;
	while (i <= sprite->r_pixel)
	{
		if (i < 0 || i >= WIDTH)
			continue ;
		j = sprite->t_pixel;
		while (j < sprite->b_pixel)
		{
			if (j < 0 || j >= HEIGHT)
				continue ;
			texture_x = (int)((i - (sprite->sprite_screen_x - \
				sprite->sprite_w / 2)) * TILE_SIZE / sprite->sprite_w);
			texture_y = (int)((j - sprite->t_pixel)
					* TILE_SIZE / sprite->sprite_h);
			draw_pixel_sprite(cub3d, get_tex_color(sprite->textures
				[cub3d->bonus_coins->load], texture_x, texture_y), i, j);
			j++;
		}
		i++;
	}
}
