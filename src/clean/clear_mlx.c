/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/28 17:47:37 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Destroy the mlx window and mlx display and free memory*/
void	ft_destroy_mlx(t_mlx *game)
{
	mlx_destroy_image(game->mlx, game->img_minimap.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free (game->mlx);
}
