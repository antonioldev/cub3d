/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:55 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/13 08:42:31 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Count the number of sprites on the map*/
static int	count_coins(t_cub3d *cub3d, int y, int x, char coin)
{
	int	count;

	count = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == coin)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/*Allocate memory for sprites and find position on the map*/
void	initiate_sprite(t_cub3d *cub3d, int i, int x, int y)
{
	char	coin;

	coin = 'C';
	cub3d->num_coins = count_coins(cub3d, 0, 0, coin);
	cub3d->coins = (t_sprite *)malloc(cub3d->num_coins * sizeof(t_sprite));
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == coin)
			{
				cub3d->coins[i].x = x;
				cub3d->coins[i].y = y;
				cub3d->coins[i].p_x = x * TILE_SIZE + TILE_SIZE / 2;
				cub3d->coins[i].p_y = y * TILE_SIZE + TILE_SIZE / 2;
				cub3d->coins[i].textures = cub3d->bonus_coins;
				cub3d->coins[i].is_visible = true;
				i++;
			}
			x++;
		}
		y++;
	}
}

/*Update the counter for the sprites animation*/
void	update_counter(t_cub3d *cub3d, int *i, int *dir)
{
	float	angle;

	angle = cub3d->p.angle;
	cub3d->bonus_coins->counter++;
	if (cub3d->bonus_coins->counter == 40)
	{
		cub3d->bonus_coins->load++;
		cub3d->bonus_coins->counter = 0;
		if (cub3d->bonus_coins->load >= FRAME_SPRITE)
			cub3d->bonus_coins->load = 0;
	}
	if (angle >= 2.5 && angle <= 5)
	{
		*i = 0;
		*dir = 1;
	}
	else
	{
		*i = cub3d->num_coins - 1;
		*dir = -1;
	}
}
