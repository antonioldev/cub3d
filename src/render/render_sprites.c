#include "../cub3d.h"

static void	update_counter(t_cub3d *cub3d, int *i, int *dir)
{
	double	angle;

	angle = cub3d->p.angle;
	cub3d->bonus_texture->counter++;
	if (cub3d->bonus_texture->counter == 40)
	{
		cub3d->bonus_texture->load++;
		cub3d->bonus_texture->counter = 0;
		if (cub3d->bonus_texture->load >= FRAME_SPRITE)
			cub3d->bonus_texture->load = 0;
	}
	// if ((angle >= 4 && angle <= 5) || (angle >= 2.5 && angle <= 3.7))
	if (angle >= 2.5 && angle <= 5)
	{
		*i = 0;
		*dir = 1;
	}
	else
	{
		*i = cub3d->num_coins - 1;
		*dir = -1;
	}
}

/*Check the color of the pixel and return it if not transparent*/
static void	draw_pixel_sprite(t_cub3d *cub3d, unsigned int color, int x, int y)
{
	int	pixel_index;

	if (color == 0xff000000)
		return ;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_index = (y * WIDTH + x) * (cub3d->game.img.bpp / 8);
		*(unsigned int *)(cub3d->game.img.addr + pixel_index) = color;
	}
}

/*Calculate the pixel that needs to be render*/
static void	draw_sprite(t_cub3d *cub3d, t_sprite *sprite, int texture_x,
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
			texture_x = (int)((i - (sprite->sprite_screen_x \
				- sprite->sprite_w / 2)) * TILE_SIZE / sprite->sprite_w);
			texture_y = (int)((j - sprite->t_pixel)
					* TILE_SIZE / sprite->sprite_h);
			draw_pixel_sprite(cub3d, get_tex_color(sprite->textures \
					[cub3d->bonus_texture->load], texture_x, texture_y), i, j);
			j++;
		}
		i++;
	}
}

/*Calculate distance and size of the sprite on the plane*/
static void	calculate_sprite(t_cub3d *cub3d, t_sprite *sprite, float angle_diff)
{
	sprite->distance = sqrt(pow(sprite->d_x, 2) + pow(sprite->d_y, 2));
	sprite->distance_to_plane = (WIDTH >> 1) / tan(cub3d->p.fov_rd / 2);
	sprite->sprite_h = ((TILE_SIZE / sprite->distance) \
		* sprite->distance_to_plane) * 0.5;
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
	double		sprite_angle;
	double		angle_diff;
	double		left_bound;
	double		right_bound;

	update_counter(cub3d, &i, &dir);
	while (i >= 0 && i < cub3d->num_coins)
	{
		sprite = &cub3d->coins[i];
		sprite->d_x = sprite->x - cub3d->p.p_x;
		sprite->d_y = sprite->y - cub3d->p.p_y;
		sprite_angle = atan2(sprite->d_y, sprite->d_x);
		angle_diff = (sprite_angle - cub3d->p.angle);
		angle_diff = nor_angle(angle_diff);
		left_bound = nor_angle(-(cub3d->p.fov_rd / 2.0));
		right_bound = nor_angle(cub3d->p.fov_rd / 2.0);
		if ((left_bound < right_bound && angle_diff >= left_bound
				&& angle_diff <= right_bound && angle_diff > 0)
			|| (left_bound > right_bound
				&& (angle_diff >= left_bound || angle_diff <= right_bound)))
			calculate_sprite(cub3d, sprite, angle_diff);
		i += dir;
	}
}
