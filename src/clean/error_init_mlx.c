/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:10 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/28 17:38:16 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initiate_error_win(t_mlx game)
{
	free(game.mlx);
	exit (EXIT_FAILURE);
}

void	initiate_error_img_minimap(t_mlx game)
{
	mlx_destroy_window(game.mlx, game.win);
	free(game.mlx);
	exit(EXIT_FAILURE);
}

void	initiate_error_addrs_minimap(t_mlx game)
{
	mlx_destroy_image(game.mlx, game.img_minimap.img);
	mlx_destroy_window(game.mlx, game.win);
	free(game.mlx);
	exit(EXIT_FAILURE);
}
