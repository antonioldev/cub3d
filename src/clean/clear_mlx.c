/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/03 16:43:25 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Destroy the mlx window and mlx display and free memory*/
void	ft_destroy_mlx(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(cub3d->game.mlx, cub3d->textures[i].img);
		i++;
	}
	mlx_destroy_image(cub3d->game.mlx, cub3d->game.img_minimap.img);
	mlx_destroy_image(cub3d->game.mlx, cub3d->game.img.img);
	mlx_destroy_window(cub3d->game.mlx, cub3d->game.win);
	mlx_destroy_display(cub3d->game.mlx);
	free (cub3d->game.mlx);
}
