/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:10 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/29 07:58:33 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Exit when window init fails, free all memory allocated*/
void	initiate_error_win(t_mlx game)
{
	free(game.mlx);
	exit (EXIT_FAILURE);
}

/*Exit when imagine minimap init fails, free all memory allocated*/
void	initiate_error_img_minimap(t_mlx game)
{
	mlx_destroy_window(game.mlx, game.win);
	free(game.mlx);
	exit(EXIT_FAILURE);
}

/*Exit when imagine 3d map init fails, free all memory allocated*/
void	initiate_error_img_map(t_mlx game)
{
	mlx_destroy_image(game.mlx, game.img_minimap.img);
	mlx_destroy_window(game.mlx, game.win);
	free(game.mlx);
	exit(EXIT_FAILURE);
}
