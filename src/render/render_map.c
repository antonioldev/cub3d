/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:50:43 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 17:31:11 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	render_map(t_cub3d *cub3d)
{
	render_mini_map(cub3d);
	mlx_destroy_image(cub3d->game.mlx, cub3d->game.img);
	cub3d->game.img = mlx_new_image(cub3d->game.mlx, cub3d->game.width,
			cub3d->game.height - 100);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win, cub3d->game.img,
		0, 100);
	return (0);
}
