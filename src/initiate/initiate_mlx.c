/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:10 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 16:53:16 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Allocate memory for mlx and create the window*/
t_mlx	initiate_mlx(void)
{
	t_mlx	game;

	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(EXIT_FAILURE);
	game.img_minimap = NULL;
	game.img = NULL;
	game.height = 600;
	game.width = 800;
	game.height_minimap = 100;
	game.tile_size = 30;//
	game.size_minimap = 4;
	game.win = mlx_new_window(game.mlx, game.width, game.height, "MAZE");
	game.img = mlx_new_image(game.mlx, game.width, game.height - 100);
	if (game.win == NULL)
	{
		free(game.mlx);
		exit (EXIT_FAILURE);
	}
	return (game);
}
