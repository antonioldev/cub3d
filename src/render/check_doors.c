/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:17:08 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/21 13:57:59 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Calculate the distance from player and find the right texture to use*/
void	check_doors(t_cub3d *cub3d, int i, int index)
{
	t_door	*door;

	while (++i < cub3d->num_doors)
	{
		door = &cub3d->doors[i];
		door->d_x = door->p_x - cub3d->p.p_x;
		door->d_y = door->p_y - cub3d->p.p_y;
		door->distance_to_player = sqrt(pow(door->d_x, 2) + pow(door->d_y, 2));
		if (door->distance_to_player > 252)
			door->texture = cub3d->bonus_door[8];
		else
		{
			index = (int)(door->distance_to_player - 100) / 20;
			if (index < 0)
				index = 0;
			door->texture = cub3d->bonus_door[index];
		}
		if (cub3d->map.map[door->y][door->x] == '0')
			cub3d->map.map[door->y][door->x] = door->type;
	}
}

static void	animation_door(t_cub3d *cub3d, t_door *door, int index)
{
	if (index == 0)
	{
		while (index < 9)
			door->texture = cub3d->bonus_door[index++];
	}
	else if (index == 8)
	{
		while (index >= 0)
			door->texture = cub3d->bonus_door[index--];
	}
}

// static void	change_door_status(t_cub3d *cub3d, t_door *door)
// {
// 	if (cub3d->p.key == true)
// 	{
// 		if (door->close == false)
// 		{
// 			door->close = true;
// 			door->texture = cub3d->bonus_door[8];
// 		}
// 		else if (door->close == true)
// 		{
// 			door->close = false;
// 			door->texture = cub3d->bonus_door[0];
// 		}
// 	}
// }

// void	check_doors(t_cub3d *cub3d, int i, int index)
// {
// 	t_door	*door;

// 	if (index == 100)
// 		return ;
// 	while (++i < cub3d->num_doors)
// 	{
// 		door = &cub3d->doors[i];
// 		door->d_x = door->p_x - cub3d->p.p_x;
// 		door->d_y = door->p_y - cub3d->p.p_y;
// 		door->distance_to_player = sqrt(pow(door->d_x, 2) + pow(door->d_y, 2));
// 		if (door->distance_to_player < 130)
// 			change_door_status(cub3d, door);
// 		if (cub3d->map.map[door->y][door->x] == '0')
// 			cub3d->map.map[door->y][door->x] = door->type;
// 	}
// 	cub3d->p.key = false;
// }
