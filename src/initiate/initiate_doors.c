/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_doors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:55 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/08 15:53:42 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Count the number of sprites on the map*/
static int	count_doors(t_cub3d *cub3d, int y, int x, char door)
{
	int	count;

	count = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == door)
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
	char	door;

	door = 'D';
	cub3d->num_doors = count_doors(cub3d, 0, 0, door);
	cub3d->doors = (t_door *)malloc(cub3d->num_doors * sizeof(t_door));
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.map[y][x] == door)
			{
				cub3d->doors[i].x = x * TILE_SIZE + TILE_SIZE / 2;
				cub3d->doors[i].y = y * TILE_SIZE + TILE_SIZE / 2;
				cub3d->doors[i].texture = cub3d->bonus_door;
				cub3d->doors[i].state = DOOR_CLOSED;
				i++;
			}
			x++;
		}
		y++;
	}
}
