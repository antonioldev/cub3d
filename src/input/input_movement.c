/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:16:20 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/19 11:40:07 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Check if player can move to new position*/
int	can_go(char **map, int dir, int left, int right)
{
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

/*Calculate the movement of the player based on the moves*/
static void	move_player(t_cub3d *cub3d, float move_x, float move_y)
{
	int	map_left;
	int	map_right;
	int	map_top;
	int	map_bottom;
	int	new_cord[2];

	new_cord[0] = roundf(cub3d->p.p_x + move_x);
	new_cord[1] = roundf(cub3d->p.p_y + move_y);
	map_left = (new_cord[0] - DISTANCE_WALL) / TILE_SIZE;
	map_right = (new_cord[0] + DISTANCE_WALL) / TILE_SIZE;
	map_top = (new_cord[1] - DISTANCE_WALL) / TILE_SIZE;
	map_bottom = (new_cord[1] + DISTANCE_WALL) / TILE_SIZE;
	if (can_go(cub3d->map.map, map_top, map_left, map_right)
		&& can_go(cub3d->map.map, map_bottom, map_left, map_right))
	{
		cub3d->p.p_x = new_cord[0];
		cub3d->p.p_y = new_cord[1];
		cub3d->map.map[cub3d->p.y][cub3d->p.x] = '0';
		cub3d->p.x = (int)floor((cub3d->p.p_x / TILE_SIZE));
		cub3d->p.y = (int)floor((cub3d->p.p_y / TILE_SIZE));
		cub3d->map.map[cub3d->p.y][cub3d->p.x] = 'P';
	}
}

static void	check_moves(t_cub3d *cub3d, float move_x, float move_y, int dir)
{
	if (dir != 0)
		move_player(cub3d, move_x, move_y);
}

/*Check if flags for rotation or movement have changed and calculate the moves*/
void	check_for_input(t_cub3d *cub3d, float move_x, float move_y)
{
	if (cub3d->p.rot != 0)
		rotate_player(cub3d, cub3d->p.rot);
	if (cub3d->p.l_r == 1)
	{
		move_x = -sin(cub3d->p.angle) * PLAYER_SPEED;
		move_y = cos(cub3d->p.angle) * PLAYER_SPEED;
	}
	else if (cub3d->p.l_r == -1)
	{
		move_x = sin(cub3d->p.angle) * PLAYER_SPEED;
		move_y = -cos(cub3d->p.angle) * PLAYER_SPEED;
	}
	check_moves (cub3d, move_x, move_y, cub3d->p.l_r);
	if (cub3d->p.u_d == 1)
	{
		move_x = cos(cub3d->p.angle) * PLAYER_SPEED;
		move_y = sin(cub3d->p.angle) * PLAYER_SPEED;
	}
	else if (cub3d->p.u_d == -1)
	{
		move_x = -cos(cub3d->p.angle) * PLAYER_SPEED;
		move_y = -sin(cub3d->p.angle) * PLAYER_SPEED;
	}
	check_moves (cub3d, move_x, move_y, cub3d->p.u_d);
}
