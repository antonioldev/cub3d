/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_doors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:55 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/21 12:07:13 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Count the number of sprites on the map*/
static int	count_doors(t_cub3d *cub3d, int y, int x)
{
	int	count;

	count = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == 'D'
				|| cub3d->map.map[y][x] == 'd')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/*Allocate memory for sprites and find position on the map*/
void	initiate_doors(t_cub3d *cub3d, int i, int x, int y)
{
	cub3d->num_doors = count_doors(cub3d, 0, 0);
	cub3d->doors = (t_door *)malloc(cub3d->num_doors * sizeof(t_door));
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == 'D'
				|| cub3d->map.map[y][x] == 'd')
			{
				cub3d->doors[i].x = x;
				cub3d->doors[i].y = y;
				cub3d->doors[i].type = cub3d->map.map[y][x];
				cub3d->doors[i].p_x = x * TILE_SIZE + TILE_SIZE / 2;
				cub3d->doors[i].p_y = y * TILE_SIZE + TILE_SIZE / 2;
				cub3d->doors[i].texture = cub3d->bonus_door[8];
				cub3d->doors[i].index = i;
				cub3d->doors[i].close = true;
				i++;
			}
			x++;
		}
		y++;
	}
}
