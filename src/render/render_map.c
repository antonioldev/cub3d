/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:50:43 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/28 17:30:52 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	render_map(t_cub3d *cub3d)
{
	clear_mini_map(&cub3d->game);
	render_mini_map(cub3d);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win,
		cub3d->game.img_minimap.img, 0, 0);
	return (0);
}

// cub3d->game.img = mlx_new_image(cub3d->game.mlx, WIDTH,
// 		HEIGHT - HEIGHT_MINI);
//raycasting(cub3d);
// mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, cub3d->game.img,
// 	0, 100);