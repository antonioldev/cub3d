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
static void	draw_map(t_cub3d *cub3d, int ray, int t_pixel, int b_pixel)
{
	int				i;
	int				y;
	unsigned int	color;
	t_texture		texture;

	texture = cub3d->bonus_door;
	i = t_pixel - 1;
	while (++i < b_pixel)
	{
		y = ((i - t_pixel) * texture.height) / (b_pixel - t_pixel);
		color = get_tex_color(texture, cub3d->ray.wall_w, y);
		draw_pixel(cub3d, ray, color, i);
	}
}

/*Calculate the door height and the top and bottom pixel for the wall*/
void	render_door(t_cub3d *cub3d, int ray)
{
	double	wall_h;
	double	b_pixel;
	double	t_pixel;

	wall_h = cub3d->ray.distance_scale / cub3d->ray.distance;
	b_pixel = (HEIGHT >> 1) + (wall_h / 2);
	t_pixel = (HEIGHT >> 1) - (wall_h / 2);
	cub3d->ray.wall_w = fmod(cub3d->ray.wall_w, TILE_SIZE);
	draw_map(cub3d, ray, t_pixel, b_pixel);
}