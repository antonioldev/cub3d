/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:16:20 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/21 13:57:29 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Check if player can move to new position*/
int	can_go(t_cub3d *cub3d, int dir, int left, int right)
{
	char	**map;

	map = cub3d->map.map;
	if ((map[dir][left] != '1' && map[dir][right] != '1')
		&& (map[dir][left] != 'C' && map[dir][right] != 'C'))
		return (1);
	return (0);
}

/*Calculate the rotation of the player*/
void	rotate_player(t_cub3d *cub3d, int i)
{
	if (i == 1)
	{
		cub3d->p.angle += ROTATION_SPEED;
		if (cub3d->p.angle > 2 * M_PI)
			cub3d->p.angle -= 2 * M_PI;
	}
	else
	{
		cub3d->p.angle -= ROTATION_SPEED;
		if (cub3d->p.angle < 0)
			cub3d->p.angle += 2 * M_PI;
	}
}

// static bool	door_collision(t_cub3d *cub3d, int *new_cord, int move_x, int move_y)
// {
// 	int	index;
// 	int	new_y;
// 	int	new_x;

// 	new_x = new_cord[0];
// 	if (move_y < 0)
// 		new_y = new_cord[1] - 32;
// 	else if (move_y >= 0)
// 		new_y = new_cord[1] + 32;
// 	if (cub3d->map.map[(int)floorf(new_y / TILE_SIZE)] \
// 		[(int)floorf(new_x / TILE_SIZE)] == 'D'
// 		|| cub3d->map.map[(int)floorf(new_y / TILE_SIZE)]
// 		[(int)floorf(new_x / TILE_SIZE)] == 'd')
// 	{
// 		index = find_index_door(cub3d, (int)floorf(new_y / TILE_SIZE),
// 				(int)floorf(new_x / TILE_SIZE));
// 		if (index >= 0 && index < cub3d->num_doors
// 			&& cub3d->doors[index].close == true)
// 			return (true);
// 	}
// 	return (false);
// }

/*Calculate the movement of the player based on the moves*/
static void	move_player(t_cub3d *cub3d, float move_x, float move_y)
{
	int	map_left;
	int	map_right;
	int	map_top;
	int	map_bottom;
	int	new_cord[2];

	new_cord[0] = (int)roundf(cub3d->p.p_x + move_x);
	new_cord[1] = (int)roundf(cub3d->p.p_y + move_y);
	// if (door_collision(cub3d, new_cord, move_x, move_y))
	// 	return ;
	map_left = (new_cord[0] - DISTANCE_WALL) / TILE_SIZE;
	map_right = (new_cord[0] + DISTANCE_WALL) / TILE_SIZE;
	map_top = (new_cord[1] - DISTANCE_WALL) / TILE_SIZE;
	map_bottom = (new_cord[1] + DISTANCE_WALL) / TILE_SIZE;
	if (can_go(cub3d, map_top, map_left, map_right)
		&& can_go(cub3d, map_bottom, map_left, map_right))
	{
		cub3d->p.p_x = new_cord[0];
		cub3d->p.p_y = new_cord[1];
		cub3d->map.map[cub3d->p.y][cub3d->p.x] = '0';
		cub3d->p.x = (int)floor((cub3d->p.p_x / TILE_SIZE));
		cub3d->p.y = (int)floor((cub3d->p.p_y / TILE_SIZE));
		cub3d->map.map[cub3d->p.y][cub3d->p.x] = 'P';
	}
}

/*Check if flags for rotation or movement have changed and calculate the moves*/
void	check_for_input(t_cub3d *cub3d)
{
	if (cub3d->p.rot != 0)
		rotate_player(cub3d, cub3d->p.rot);
	if (cub3d->p.l_r == 1)
		move_player(cub3d, -sin(cub3d->p.angle) * PLAYER_SPEED, \
			cos(cub3d->p.angle) * PLAYER_SPEED);
	else if (cub3d->p.l_r == -1)
		move_player(cub3d, sin(cub3d->p.angle) * PLAYER_SPEED, \
			-cos(cub3d->p.angle) * PLAYER_SPEED);
	if (cub3d->p.u_d == 1)
		move_player(cub3d, cos(cub3d->p.angle) * PLAYER_SPEED, \
			sin(cub3d->p.angle) * PLAYER_SPEED);
	else if (cub3d->p.u_d == -1)
		move_player(cub3d, -cos(cub3d->p.angle) * PLAYER_SPEED, \
			-sin(cub3d->p.angle) * PLAYER_SPEED);
}
