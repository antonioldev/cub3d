/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mini_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:48:08 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/28 17:27:26 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Fill the mini map area with black pixels*/
void	clear_mini_map(t_mlx *game)
{
	int		x;
	int		y;
	int		*pixel_addr;
	t_img	img;

	img = game->img_minimap;
	y = 0;
	while (y < HEIGHT_MINI)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_addr = (int *)(img.addr + y * \
					img.line_length + x * (img.bpp / 8));
			*pixel_addr = 0x0;
			x++;
		}
		y++;
	}
}
