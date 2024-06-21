/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:18:53 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/21 12:22:00 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Exit the loop when pressing X button*/
int	x_pressed(t_cub3d *cub3d)
{
	return (mlx_loop_end (cub3d->game.mlx));
}

/*it handles the input when key press event is called*/
int	key_press(int ks, t_cub3d *cub3d)
{
	t_mlx	*game;

	game = &cub3d->game;
	if (ks == XK_Escape)
		return (mlx_loop_end (game->mlx));
	if (ks == 115)
		cub3d->p.u_d = -1;
	else if (ks == 119)
		cub3d->p.u_d = 1;
	if (ks == 97)
		cub3d->p.l_r = -1;
	else if (ks == 100)
		cub3d->p.l_r = 1;
	if (ks == XK_Left)
		cub3d->p.rot = -1;
	else if (ks == XK_Right)
		cub3d->p.rot = 1;
	if (ks == 101)
		cub3d->p.key = true;
	return (0);
}

/*it handles the input when key release event is called*/
int	key_release(int ks, t_cub3d *cub3d)
{
	if (ks == 115 || ks == 119)
		cub3d->p.u_d = 0;
	if (ks == 97 || ks == 100)
		cub3d->p.l_r = 0;
	if (ks == XK_Left || ks == XK_Right)
		cub3d->p.rot = 0;
	return (0);
}
