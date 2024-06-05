/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:18:53 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/28 17:09:12 by antonio          ###   ########.fr       */
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
	else if (ks == 115)
		ft_move_down(map);
	else if (ks == 119)
		ft_move_up(map);
	else if (ks == 97)
		ft_move_left(map);
	else if (ks == 100)
		ft_move_right(map);
	return (0);
}
