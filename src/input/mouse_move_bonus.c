/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:27:56 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/21 10:15:30 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	handle_mouse(int button, t_cub3d *cub3d)
{
	if (button == 1)
	{
		cub3d->p.rot = -1;
		rotate_player(cub3d, -1);
	}
	if (button == 3)
	{
		cub3d->p.rot = 1;
		rotate_player(cub3d, 1);
	}
}

int	mouse_press(int button, int x, int y, t_cub3d *cub3d)
{
	if (button == 1 || button == 3)
		handle_mouse(button, cub3d);
	return (x * y);
}

int	mouse_release(int button, int x, int y, t_cub3d *cub3d)
{
	if (button == 1 || button == 3)
		cub3d->p.rot = 0;
	return (x * y);
}

int	mouse_move(int x, int y, t_cub3d *cub3d)
{
	if (x != cub3d->p.mouse_y)
	{
		if (x < cub3d->p.mouse_y)
		{
			cub3d->p.rot = -1;
			rotate_player(cub3d, -1);
		}
		else if (x > cub3d->p.mouse_y)
		{
			cub3d->p.rot = 1;
			rotate_player(cub3d, 1);
		}
		cub3d->p.mouse_y = x;
	}
	cub3d->p.rot = 0;
	return (x * y);
}
