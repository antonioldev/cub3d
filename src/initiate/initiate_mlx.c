/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:13:10 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/01 09:14:54 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Return the addres of the image passed as parameter*/
static char	*get_address(t_img *img)
{
	return (mlx_get_data_addr(img->img, &img->bpp, \
		&img->line_length, &img->endian));
}

/*Set all variable of mlx to NULL*/
static void	init_mlx_args(t_mlx *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img.img = NULL;
	game->img_minimap.img = NULL;
}

/*Allocate memory for mlx and create the window*/
t_mlx	initiate_mlx(void)
{
	t_mlx	game;

	init_mlx_args(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(EXIT_FAILURE);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT + HEIGHT_MINI, "MAZE");
	if (game.win == NULL)
		initiate_error_win(game);
	game.img_minimap.img = mlx_new_image(game.mlx, WIDTH, HEIGHT_MINI);
	if (game.img_minimap.img == NULL)
		initiate_error_img_minimap(game);
	game.img_minimap.addr = get_address(&game.img_minimap);
	game.img.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (game.img.img == NULL)
		initiate_error_img_map(game);
	game.img.addr = get_address(&game.img);
	return (game);
}
