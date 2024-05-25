/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:21:29 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 17:25:06 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player	initiate_player(t_cub3d *cub3d)
{
	t_player	player;
	int			tile;

	tile = cub3d->game.tile_size;
	player.pl_speed = 3;
	player.rot = 0;
	player.rot_speed = 0.020;
	player.pl_x = cub3d->map.x * tile + tile / 2;
	player.pl_y = cub3d->map.y * tile + tile / 2;
	player.fov_rd = (60 * 3.14) / 180;//UUU
	player.angle = 3.14;//UU
	return (player);
}
