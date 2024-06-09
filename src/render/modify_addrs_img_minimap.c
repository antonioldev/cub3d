/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_addrs_img_minimap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:13:06 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/08 15:43:54 by alimotta         ###   ########.fr       */
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
