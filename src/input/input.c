/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:18:53 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 16:51:40 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Exit the loop when pressing X button*/
int	x_pressed(t_cub3d *cub3d)
{
	return (mlx_loop_end (cub3d->game.mlx));
}

/*It handles the keybord input*/
int	handle_input(int ks, t_cub3d *cub3d)
{
	t_map	*map;
	t_mlx	*game;
	int		pos[2];

	map = &cub3d->map;
	game = &cub3d->game;
	pos[0] = map->x;
	pos[1] = map->y;
	if (ks == XK_Escape)
		return (mlx_loop_end (game->mlx));
	else if (ks == 115)
		ft_move_down(map);
	else if (ks == 119)
		ft_move_up(map);
	else if (ks == 97)
		ft_move_left(map);
	else if (ks == 100)
		ft_move_right(map);
	if (pos[0] != map->x || pos[1] != map->y)
		clear_mini_map(cub3d);
	return (0);
}
