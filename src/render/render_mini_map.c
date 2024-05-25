/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:32:36 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 16:45:38 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Return the color based on type of item of the map*/
static int	pick_color(char c)
{
	if (c == '1')
		return (0x696969);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'P')
		return (0xff0000);
	else
		return (0x0);
}

/*Draw more pixel for each part of the map*/
static void	draw_square(t_mlx *game, int w, int h, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size_minimap)
	{
		j = 0;
		while (j < game->size_minimap)
		{
			mlx_pixel_put(game->mlx, game->win, w + j, h + i, color);
			j++;
		}
		i++;
	}
}

/*Calculate and return the position on the x axis*/
static int	pos_screen_x(t_cub3d *cub3d, int w)
{
	int	screen_x;
	int	player_screen_x;
	int	size;

	player_screen_x = 400;
	size = cub3d->game.size_minimap;
	screen_x = player_screen_x + (w - cub3d->map.x) * size;
	return (screen_x);
}

/*Calculate and return the position on the y axis*/
static int	pos_screen_y(t_cub3d *cub3d, int h)
{
	int	screen_y;
	int	player_screen_y;
	int	size;

	player_screen_y = 48;
	size = cub3d->game.size_minimap;
	screen_y = player_screen_y + (h - cub3d->map.y) * size;
	return (screen_y);
}

/*Rendering map top point of view*/
int	render_mini_map(t_cub3d *cub3d)
{
	int	start_y;
	int	end_y;
	int	w;
	int	h;

	start_y = cub3d->map.y - 12;
	end_y = cub3d->map.y + 12;
	h = start_y;
	while (h <= end_y)
	{
		if (h >= 0 && h < cub3d->map.height)
		{
			w = 0;
			while (cub3d->map.map[h][w])
			{
				draw_square(&cub3d->game, pos_screen_x(cub3d, w),
					pos_screen_y(cub3d, h), pick_color(cub3d->map.map[h][w]));
				w++;
			}
		}
		h++;
	}
	return (0);
}
