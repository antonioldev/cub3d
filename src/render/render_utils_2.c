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
			int map_x, int map_y)
{
	int		step_dir_x;
	int		step_dir_y;
	float	side_dist_x;
	float	side_dist_y;

	side_dist_x = set_direction_x(cub3d, sprite, &step_dir_x);
	side_dist_y = set_direction_y(cub3d, sprite, &step_dir_y);
	while (map_x >= 0 && map_x < cub3d->map.width && map_y >= 0
		&& map_y < cub3d->map.height)
	{
		if (cub3d->map.map[map_y][map_x] == '1')
			// || cub3d->map.map[map_y][map_x] == 'D'
			// || cub3d->map.map[map_y][map_x] == 'd')
			return (false);
		if (map_y == sprite->y && map_x == sprite->x)
			return (true);
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += sprite->delta_x;
			map_x += step_dir_x;
			continue ;
		}
		side_dist_y += sprite->delta_y;
		map_y += step_dir_y;
	}
	return (false);
}