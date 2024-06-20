/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:21:29 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/20 15:37:50 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Set the angle based on the player orientation*/
float	calculate_angle(char c)
{
	if (c == 'N')
		return ((3 * M_PI) / 2);
	else if (c == 'S')
		return (M_PI / 2);
	else if (c == 'E')
		return (0);
	else
		return (M_PI);
}

/*Initiate the player struct
 - Calculate the center of the tile
 - Calculate the field of view in radians (convert degrees into radian)
 - Set the player angle*/
t_player	initiate_player(t_map map)
{
	t_player	player;

	player.x = map.x;
	player.y = map.y;
	player.p_x = map.x * TILE_SIZE + TILE_SIZE / 2;
	player.p_y = map.y * TILE_SIZE + TILE_SIZE / 2;
	player.fov_rd = (FOV * M_PI) / 180;
	player.distance_to_plane = (WIDTH / 2) / tan(player.fov_rd / 2);
	player.angle = calculate_angle(map.player_orientation);
	player.l_r = 0;
	player.u_d = 0;
	player.rot = 0;
	player.mouse_y = 0;
	return (player);
}
