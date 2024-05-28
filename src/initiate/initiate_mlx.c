/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:10 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/28 17:54:57 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*get_address(t_img *img)
{
	return (mlx_get_data_addr(img->img, &img->bpp, \
		&img->line_length, &img->endian));
}

static void	init_mlx_args(t_mlx *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->img_minimap.img = NULL;
	game->size_minimap = 4;
}

/*Allocate memory for mlx and create the window*/
t_mlx	initiate_mlx(void)
{
	t_mlx	game;

	init_mlx_args(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MAZE");
	if (game.win == NULL)
		initiate_error_win(game);
	game.img_minimap.img = mlx_new_image(game.mlx, WIDTH, HEIGHT_MINI);
	if (game.img_minimap.img == NULL)
		initiate_error_img_minimap(game);
	game.img_minimap.addr = get_address(&game.img_minimap);
	if (game.img_minimap.addr == NULL)
		initiate_error_addrs_minimap(game);
	return (game);
}

// game.img->img = mlx_new_image(game.mlx, WIDTH, HEIGHT - HEIGHT_MINI - 1);
//game.img_minimap->img = mlx_new_image(game.mlx, WIDTH, HEIGHT_MINI);