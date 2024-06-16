/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:38:34 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 17:25:29 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	open_door(t_cub3d *cub3d, int y, int x)
{
	int	index;

	index = find_index_door(cub3d, y, x);
	if (cub3d->doors[index].texture.index < 4)
		return (true);
	return (false);
}

/*sets up the parameters needed for the Digital
	 Differential Analyzer (DDA) algorithm */
static float	set_direction_y(t_cub3d *cub3d, t_sprite *sprite, int *step_dir)
{
	float	current;
	float	dist;
	float	delta;
	int		map;

	current = cub3d->p.p_y;
	map = (int)(current / TILE_SIZE);
	dist = sprite->d_y;
	delta = sprite->delta_y;
	if (dist < 0)
	{
		(*step_dir) = -1;
		return ((current / TILE_SIZE - map) * delta);
	}
	else
	{
		(*step_dir) = 1;
		return ((map + 1.0 - current / TILE_SIZE) * delta);
	}
}

/*sets up the parameters needed for the Digital
	 Differential Analyzer (DDA) algorithm */
static float	set_direction_x(t_cub3d *cub3d, t_sprite *sprite, int *step_dir)
{
	float	current;
	float	dist;
	float	delta;
	int		map;

	current = cub3d->p.p_x;
	map = (int)(current / TILE_SIZE);
	dist = sprite->d_x;
	delta = sprite->delta_x;
	if (dist < 0)
	{
		(*step_dir) = -1;
		return ((current / TILE_SIZE - map) * delta);
	}
	else
	{
		(*step_dir) = 1;
		return ((map + 1.0 - current / TILE_SIZE) * delta);
	}
}

/*Check if the sprite is not behind a wall*/
bool	is_sprite_visible(t_cub3d *cub3d, t_sprite *sprite,
			int x, int y)
{
	int		step_dir[2];
	float	side_dist[2];

	side_dist[0] = set_direction_x(cub3d, sprite, &step_dir[0]);
	side_dist[1] = set_direction_y(cub3d, sprite, &step_dir[1]);
	while (x >= 0 && x < cub3d->map.width && y >= 0 && y < cub3d->map.height)
	{
		if (cub3d->map.map[y][x] == '1')
			return (false);
		if (cub3d->map.map[y][x] == 'D' || cub3d->map.map[y][x] == 'd')
			if (!open_door(cub3d, y, x))
				return (false);
		if (y == sprite->y && x == sprite->x)
			return (true);
		if (side_dist[0] < side_dist[1])
		{
			side_dist[0] += sprite->delta_x;
			x += step_dir[0];
			continue ;
		}
		side_dist[1] += sprite->delta_y;
		y += step_dir[1];
	}
	return (false);
}
