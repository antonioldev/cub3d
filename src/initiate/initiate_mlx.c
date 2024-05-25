/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:10 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 09:03:09 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	load_images(t_mlx *game, t_map *map)
{
	int	img_w;
	int	img_h;

	return ;//testing
	game->img_n = mlx_xpm_file_to_image(game->mlx, map->no, &img_w, &img_h);
	game->img_s = mlx_xpm_file_to_image(game->mlx, map->so, &img_w, &img_h);
	game->img_w = mlx_xpm_file_to_image(game->mlx, map->we, &img_w, &img_h);
	game->img_e = mlx_xpm_file_to_image(game->mlx, map->ea, &img_w, &img_h);
}

/*Allocate memory for mlx and create the window*/
t_mlx	initiate_mlx(t_map *map)
{
	t_mlx	game;

	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(EXIT_FAILURE);
	game.height = 600;
	game.width = 800;
	game.height_minimap = 100;
	game.size_minimap = 4;
	game.win = mlx_new_window(game.mlx, game.width, game.height, "MAZE");
	if (game.win == NULL)
	{
		free(game.mlx);
		exit (EXIT_FAILURE);
	}
	load_images(&game, map);
	return (game);
}
