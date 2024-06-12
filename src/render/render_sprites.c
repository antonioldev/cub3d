/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:32:36 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/02 10:04:22 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// /*Calculate distance and size of the sprite on the plane*/
static void	calculate_sprite(t_cub3d *cub3d, t_sprite *sprite, float angle_diff)
{
	sprite->distance_to_plane = (WIDTH >> 1) / tan(cub3d->p.fov_rd / 2);
	sprite->sprite_h = ((TILE_SIZE / sprite->distance)
			* sprite->distance_to_plane) * 0.20;
	sprite->sprite_w = sprite->sprite_h;
	sprite->sprite_screen_x = (WIDTH / 2) * \
		(1 + tan(angle_diff) / tan(cub3d->p.fov_rd / 2));
	sprite->b_pixel = (int)(HEIGHT >> 1) + (sprite->sprite_h / 2);
	sprite->t_pixel = (int)(HEIGHT >> 1) - (sprite->sprite_h / 2);
	sprite->l_pixel = (int)(sprite->sprite_screen_x - sprite->sprite_h / 2);
	sprite->r_pixel = (int)(sprite->sprite_screen_x + sprite->sprite_h / 2);
	if (sprite->b_pixel >= HEIGHT)
		sprite->b_pixel = HEIGHT - 1;
	if (sprite->t_pixel < 0)
		sprite->t_pixel = 0;
	if (sprite->l_pixel < 0)
		sprite->l_pixel = 0;
	if (sprite->r_pixel >= WIDTH)
		sprite->r_pixel = WIDTH - 1;
	draw_sprite(cub3d, sprite, 0, 0);
}

/*sets up the parameters needed for the Digital
	 Differential Analyzer (DDA) algorithm */
static float	set_direction_y(t_cub3d *cub3d, t_sprite *sprite, int *step_dir)
{
	float	current;
	double	dist;
	double	delta;
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
	double	dist;
	double	delta;
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
		if (cub3d->map.map[map_y][map_x] == '1')//add door
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

// /*Check if sprite is in FOV of camera*/
void	render_sprite(t_cub3d *cub3d, int i, int dir)
{
	t_sprite	*sprite;
	double		sprite_angle;
	double		angle_diff;

	update_counter(cub3d, &i, &dir);
	while (i >= 0 && i < cub3d->num_coins)
	{
		sprite = &cub3d->coins[i];
		sprite->d_x = sprite->p_x - cub3d->p.p_x;
		sprite->d_y = sprite->p_y - cub3d->p.p_y;
		sprite->delta_x = fabs(1 / sprite->d_x);
		sprite->delta_y = fabs(1 / sprite->d_y);
		sprite_angle = atan2(sprite->d_y, sprite->d_x);
		angle_diff = nor_angle(sprite_angle - cub3d->p.angle);
		sprite->distance = sqrt(pow(sprite->d_x, 2) + pow(sprite->d_y, 2));
		if (((angle_diff >= -0.6 && angle_diff <= 0.6) || (angle_diff >= 5.7))
			&& is_sprite_visible(cub3d, sprite, 
			(int)(cub3d->p.p_x / TILE_SIZE), (int)(cub3d->p.p_y / TILE_SIZE)))
			calculate_sprite(cub3d, sprite, angle_diff);
		i += dir;
	}
}
