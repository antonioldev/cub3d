/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:43:12 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/01 14:53:58 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Update the player position in map array*/
static void	update_player_position_map(t_cub3d *cub3d, int y, int x)
{
	int	old_y;
	int	old_x;

	old_y = cub3d->map.y;
	old_x = cub3d->map.x;
	if (cub3d->map.y != y || cub3d->map.x != x)
	{
		cub3d->map.y = y;
		cub3d->map.x = x;
		cub3d->map.map[old_y][old_x] = '0';
		cub3d->map.map[y][x] = 'P';
	}
}

/*Calculate the rotation of the player*/
static void	rotate_player(t_cub3d *cub3d, int i)
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
	cub3d->p.rot = 0;
}

/*Calculate the movement of the player based on the moves*/
static void	move_player(t_cub3d *cub3d, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = roundf(cub3d->p.p_x + move_x);
	new_y = roundf(cub3d->p.p_y + move_y);
	map_x = (new_x / TILE_SIZE);
	map_y = (new_y / TILE_SIZE);
	if (cub3d->map.map[map_y][map_x] != '1' && \
	(cub3d->map.map[map_y][cub3d->p.p_x / TILE_SIZE] != '1' && \
	cub3d->map.map[cub3d->p.p_y / TILE_SIZE][map_x] != '1'))
	{
		update_player_position_map(cub3d, map_y, map_x);
		cub3d->p.p_x = new_x;
		cub3d->p.p_y = new_y;
	}
}

/*Check if flags for rotation or movement have changed and calculate the moves*/
void	check_for_input(t_cub3d *cub3d, double move_x, double move_y)
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
	move_player(cub3d, move_x, move_y);
	cub3d->p.u_d = 0;
	cub3d->p.l_r = 0;
}
