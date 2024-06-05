/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:43:12 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 13:47:31 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_down(t_map *map)
{
	int	*x;
	int	*y;

	x = &map->x;
	y = &map->y;
	if (map->map[*y + 1][*x] != '1')
	{
		map->map[*y][*x] = '0';
		map->y += 1;
		map->map[*y][*x] = 'P';
	}
}

void	ft_move_up(t_map *map)
{
	int	*x;
	int	*y;

	x = &map->x;
	y = &map->y;
	if (map->map[*y - 1][*x] != '1')
	{
		map->map[*y][*x] = '0';
		map->y -= 1;
		map->map[*y][*x] = 'P';
	}
}

void	ft_move_right(t_map *map)
{
	int	*x;
	int	*y;

	x = &map->x;
	y = &map->y;
	if (map->map[*y][*x + 1] != '1')
	{
		map->map[*y][*x] = '0';
		map->x += 1;
		map->map[*y][*x] = 'P';
	}
}

void	ft_move_left(t_map *map)
{
	int	*x;
	int	*y;

	x = &map->x;
	y = &map->y;
	if (map->map[*y][*x - 1] != '1')
	{
		map->map[*y][*x] = '0';
		map->x -= 1;
		map->map[*y][*x] = 'P';
	}
}
