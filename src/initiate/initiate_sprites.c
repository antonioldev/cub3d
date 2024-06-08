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

void	initiate_sprite(t_cub3d *cub3d,int i, int x, int y)
{
	cub3d->map.map[y][x] = 'C';
	cub3d->coins[i].x = x * TILE_SIZE + TILE_SIZE / 2;
	cub3d->coins[i].y = y * TILE_SIZE + TILE_SIZE / 2;
	cub3d->coins[i].textures = cub3d->bonus_texture;
}
