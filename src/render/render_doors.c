/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:50:43 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/08 15:52:06 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_doors(t_cub3d *cub3d)
{
	t_door	*door;
	int		i;

	i = 0;
	while (i < cub3d->num_doors)
	{
		door = &cub3d->doors[i];
		door->d_x = cub3d->p.p_x - door->x;
		door->d_y = cub3d->p.p_y - door->y;
		door->distance_to_player = sqrt(door->d_x * door->d_x + door->d_y * door->d_y);
		if (door->distance_to_player < DOOR_OPEN_DISTANCE)
		{
			if (door->state == DOOR_CLOSED)
				door->state = DOOR_OPENING;
		}
		else
		{
			if (door->state == DOOR_OPEN)
				door->state = DOOR_CLOSED;
		}
		i++;
	}
}

/*Draw the 3d map using its address, each loop draw different parts of the map
respectively cealing, walls, floor*/
// static void	draw_map(t_cub3d *cub3d, int ray, int t_pixel, int b_pixel)
// {
// 	int				i;
// 	int				y;
// 	unsigned int	color;
// 	t_texture		texture;

// 	texture = cub3d->bonus_door;
// 	i = t_pixel - 1;
// 	while (++i < b_pixel)
// 	{
// 		y = ((i - t_pixel) * texture.height) / (b_pixel - t_pixel);
// 		color = get_tex_color(texture, cub3d->ray.wall_w, y);
// 		draw_pixel(cub3d, ray, color, i);
// 	}
// }

/*Calculate the door height and the top and bottom pixel for the wall*/
// void	render_door(t_cub3d *cub3d, int ray)
// {
// 	double	wall_h;
// 	double	b_pixel;
// 	double	t_pixel;

// 	wall_h = cub3d->ray.distance_scale / cub3d->ray.distance;
// 	b_pixel = (HEIGHT >> 1) + (wall_h / 2);
// 	t_pixel = (HEIGHT >> 1) - (wall_h / 2);
// 	cub3d->ray.wall_w = fmod(cub3d->ray.wall_w, TILE_SIZE);
// 	draw_map(cub3d, ray, t_pixel, b_pixel);
// }
static void	draw_pixel_sprite(t_cub3d *cub3d, unsigned int color, int x, int y)
{
	int	pixel_index;

	// if (color == 0xff000000)
	// 	return ;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_index = (y * WIDTH + x) * (cub3d->game.img.bpp / 8);
		*(unsigned int *)(cub3d->game.img.addr + pixel_index) = color;
	}
}

static void	draw_door(t_cub3d *cub3d, t_door *sprite, int texture_x,
	int texture_y)
{
	int				i;
	int				j;

	i = sprite->l_pixel;
	while (i <= sprite->r_pixel)
	{
		if (i < 0 || i >= WIDTH)
			continue ;
		j = sprite->t_pixel;
		while (j < sprite->b_pixel)
		{
			if (j < 0 || j >= HEIGHT)
				continue ;
			texture_x = (int)((i - (sprite->sprite_screen_x - \
				sprite->sprite_w / 2)) * TILE_SIZE / sprite->sprite_w);
			texture_y = (int)((j - sprite->t_pixel)
					* TILE_SIZE / sprite->sprite_h);
			draw_pixel_sprite(cub3d, get_tex_color(cub3d->bonus_door, texture_x, texture_y), i, j);
			j++;
		}
		i++;
	}
}

static void	calculate_sprite(t_cub3d *cub3d, t_door *sprite, float angle_diff)
{
	sprite->distance_to_plane = (WIDTH >> 1) / tan(cub3d->p.fov_rd / 2);
	sprite->sprite_h = ((TILE_SIZE / sprite->distance)
			* sprite->distance_to_plane);
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
	draw_door(cub3d, sprite, 0, 0);
}
void	render_door(t_cub3d *cub3d, int i, int dir)
{
	t_door	*sprite;
	double	sprite_angle;
	double	angle_diff;
	if (dir == 10)
		return ;
	while (i < cub3d->num_doors)
	{
		sprite = &cub3d->doors[i];
		sprite->d_x = sprite->x - cub3d->p.p_x;
		sprite->d_y = sprite->y - cub3d->p.p_y;
		sprite->delta_x = fabs(1 / sprite->d_x);
		sprite->delta_y = fabs(1 / sprite->d_y);
		sprite_angle = atan2(sprite->d_y, sprite->d_x);
		angle_diff = nor_angle(sprite_angle - cub3d->p.angle);	
		sprite->distance = sqrt(pow(sprite->d_x, 2) + pow(sprite->d_y, 2));
		// if (((angle_diff >= -0.6 && angle_diff <= 0.6) || (angle_diff >= 5.7)))
			// && is_sprite_visible(cub3d, sprite, 
			// (int)(cub3d->p.p_x / TILE_SIZE), (int)(cub3d->p.p_y / TILE_SIZE)))
			calculate_sprite(cub3d, sprite, angle_diff);
		i ++;
	}
}