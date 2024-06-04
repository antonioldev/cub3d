/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_addrs_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:03:19 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/04 19:13:49 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Fill the mini map area with black pixels*/
void	clear_mini_map(t_mlx *game)
{
	int		x;
	int		y;
	char	*pixel_addr;
	t_img	*img;

	img = &game->img_minimap;
	y = 0;
	while (y < HEIGHT_MINI)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_addr = (img->addr + y * \
					img->line_length + x * (img->bpp / 8));
			*(unsigned int *)pixel_addr = 0x0;
			x++;
		}
		y++;
	}
}

/*Draw more pixel for each part of the map*/
void	draw_square_minimap(t_mlx *game, int w, int h, int color)
{
	int		i;
	int		j;
	char	*pixel_addr;

	i = 0;
	while (i < PIXEL_MINI)
	{
		j = 0;
		while (j < PIXEL_MINI)
		{
			pixel_addr = game->img_minimap.addr + ((h + i) * \
					game->img_minimap.line_length + (w + j) * \
					(game->img_minimap.bpp / 8));
			if (pixel_addr < game->img_minimap.addr + \
					game->img_minimap.line_length * HEIGHT_MINI)
				*(unsigned int *)pixel_addr = color;
			j++;
		}
		i++;
	}
}

/*Assign the proper color to a specific pixel*/
void	draw_pixel(t_cub3d *cub3d, int ray, int color, int i)
{
	char	*pixel_addr;

	pixel_addr = cub3d->game.img.addr + (i * cub3d->game.img.line_length + \
			ray * (cub3d->game.img.bpp / 8));
	// if (pixel_addr < cub3d->game.img.addr + cub3d->game.img.line_length * \
	// 		HEIGHT)
		*(unsigned int *)pixel_addr = color;
}

/*Get the right color/pattern for the walls, in order W E S N*/
int	get_color(t_cub3d *cub3d, int flag)
{
	cub3d->ray.ray_ngl = nor_angle(cub3d->ray.ray_ngl);
	if (flag == 0)
	{
		if (cub3d->ray.ray_ngl > M_PI / 2
			&& cub3d->ray.ray_ngl < 3 * (M_PI / 2))
			return (WEST);//(0xFF6666);
		else
			return (EAST);//(0xFF0000);
	}
	else
	{
		if (cub3d->ray.ray_ngl > 0 && cub3d->ray.ray_ngl < M_PI)
			return (SOUTH);//(0x990000);
		else
			return (NORTH);//(0x660000);
	}
}

/*Draw the 3d map using its address, each loop draw different parts of the map
respectively cealing, walls, floor*/
// void	draw_map(t_cub3d *cub3d, int ray, int t_pixel, int b_pixel)
// {
// 	int		i;

// 	i = 0;
// 	while (i++ < t_pixel)
// 		draw_pixel(cub3d, ray, 0xFFFFFF, i);
// 	i = b_pixel;
// 	while (i++ < HEIGHT)
// 		draw_pixel(cub3d, ray, (0x808080), i);
// 	while (t_pixel++ < b_pixel)
// 	 	draw_pixel(cub3d, ray, get_color(cub3d, cub3d->ray.flag), t_pixel);
// }

void draw_map(t_cub3d *cub3d, int ray, int t_pixel, int b_pixel) {
    int i, tex_x, tex_y;
    t_texture *texture;
    double tex_pos, step;

    texture = &cub3d->textures[get_color(cub3d, cub3d->ray.flag)];

    // Calculate texture x-coordinate
    tex_x = (int)((cub3d->ray.wall_x / TILE_SIZE) * texture->width);
    if ((cub3d->ray.flag == 0 && cub3d->ray.ray_ngl > M_PI && cub3d->ray.ray_ngl < 2 * M_PI) ||
        (cub3d->ray.flag == 1 && cub3d->ray.ray_ngl > M_PI / 2 && cub3d->ray.ray_ngl < 3 * M_PI / 2)) {
        tex_x = texture->width - tex_x - 1;
    }

    // Calculate step and initial texture position
    step = 1.0 * texture->height / (b_pixel - t_pixel);
    tex_pos = (t_pixel - HEIGHT / 2 + (b_pixel - t_pixel) / 2) * step;

    // Draw ceiling
    for (i = 0; i < t_pixel; i++) {
        draw_pixel(cub3d, ray, 0xFFFFFF, i);
    }

    // Draw wall with texture
    for (i = t_pixel; i < b_pixel; i++) {
        tex_y = (int)tex_pos & (texture->height - 1);
        tex_pos += step;
        int color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x * (texture->bpp / 8)));
        draw_pixel(cub3d, ray, color, i);
    }

    // Draw floor
    for (i = b_pixel; i < HEIGHT; i++) {
        draw_pixel(cub3d, ray, 0x808080, i);
    }
}