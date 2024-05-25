/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:18:53 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 09:50:57 by alimotta         ###   ########.fr       */
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

	map = &cub3d->map;
	game = &cub3d->game;
	if (ks == XK_Escape)
		return (mlx_loop_end (game->mlx));
	else if (ks == XK_Down)
		ft_move_down(map);
	else if (ks == 65362)
		ft_move_up(map);
	else if (ks == 65361)
		ft_move_left(map);
	else if (ks == 65363)
		ft_move_right(map);
	clear_mini_map(cub3d);
	return (0);
}
