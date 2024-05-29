/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:21:29 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/29 17:02:42 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initiate_orientation(t_view *player, char c)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

t_view	initiate_player(t_map map)
{
	t_view	player;

	player.x = map.x;
	player.y = map.y;
	initiate_orientation(&player, map.player_orientation);
	// player.dir_x = 0; //TODO update with position
	// player.dir_y = 1;
	player.plane_x = 0;
	player.plane_y = 0.66;
	// player.pl_speed = 3;
	// player.rot = 0;
	// player.rot_speed = 0.020;
	player.distance = 0;
	player.flag = 0;
	player.ray_ngl = 0;


	// player.map_x = 0;
	// player.map_y = 0;
	// player.side = 0;
	// player.camera_x = 0;//coordinate on the camera plane that the current x-coordinate of the screen represents
	// player.ray_dir_x = 0;
	// player.ray_dir_y = 0;
	// player.delta_dist_x = 0;// distance the ray has to travel to go from 1 x-side to the next side
	// player.delta_dist_y = 0;
	// player.side_dist_x = 0;
	// player.side_dist_y = 0;
	// player.line_height = 0;
	// player.draw_start = 0;
	// player.draw_end = 0;
	return (player);
}
