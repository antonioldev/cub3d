/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mini_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:48:08 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 10:05:46 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Fill the mini map area with black pixels*/
void	clear_mini_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub3d->game.height_minimap)
	{
		x = 0;
		while (x < cub3d->game.width)
		{
			mlx_pixel_put(cub3d->game.mlx, cub3d->game.win, x, y, 0x0);
			x++;
		}
		y++;
	}
}
