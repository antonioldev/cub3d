/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:55 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/08 15:53:42 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_coins(t_cub3d *cub3d, int y, int x)
{
	int	count;

	count = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	initiate_sprite(t_cub3d *cub3d,int i, int x, int y)
{
	if (i == 1 || x == 1 || y == 1)
		return ;
	cub3d->num_coins = count_coins(cub3d, 0, 0);
	cub3d->coins = (t_sprite *)malloc(cub3d->num_coins * sizeof(t_sprite));
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == 'C')
			{
				cub3d->coins[i].x = x * TILE_SIZE + TILE_SIZE / 2;
				cub3d->coins[i].y = y * TILE_SIZE + TILE_SIZE / 2;
				cub3d->coins[i].textures = cub3d->bonus_texture;
				i++;
			}
			x++;
		}
		y++;
	}
}
