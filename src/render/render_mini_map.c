/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:32:36 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/01 09:16:26 by alimotta         ###   ########.fr       */
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

/*Calculate and return the position on the x axis*/
static int	pos_screen_x(t_cub3d *cub3d, int w)
{
	int	screen_x;
	int	player_screen_x;

	player_screen_x = WIDTH / 2;
	screen_x = player_screen_x + (w - cub3d->map.x) * PIXEL_MINI;
	return (screen_x);
}

/*Calculate and return the position on the y axis*/
static int	pos_screen_y(t_cub3d *cub3d, int h)
{
	int	screen_y;
	int	player_screen_y;

	player_screen_y = HEIGHT_MINI / 2;
	screen_y = player_screen_y + (h - cub3d->map.y) * PIXEL_MINI;
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
				draw_square_minimap(&cub3d->game, pos_screen_x(cub3d, w),
					pos_screen_y(cub3d, h), pick_color(cub3d->map.map[h][w]));
				w++;
			}
		}
		h++;
	}
	return (0);
}
