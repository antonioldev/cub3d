/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:32:36 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 16:39:34 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Calculate distance and size of the sprite on the plane*/
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

/*Check if sprite is in FOV of camera*/
void	render_sprite(t_cub3d *cub3d, int i, int dir)
{
	t_sprite	*sprite;
	float		sprite_angle;
	float		angle_diff;

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
			&& is_sprite_visible(cub3d, sprite, \
			(int)(cub3d->p.p_x / TILE_SIZE), (int)(cub3d->p.p_y / TILE_SIZE)))
			calculate_sprite(cub3d, sprite, angle_diff);
		i += dir;
	}
}
