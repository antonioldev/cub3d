/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/24 15:41:13 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_cub3d	cub3d;

	fd = ft_error(argc, argv);
	map_init(&cub3d.map, fd);
	cub3d.game = initiate_mlx(&cub3d.map);
	mlx_hook(cub3d.game.win, 17, 1L << 0, x_pressed, &cub3d);
	mlx_hook(cub3d.game.win, 3, 1L << 1, handle_input, &cub3d);
	mlx_loop_hook(cub3d.game.mlx, render_mini_map, &cub3d);
	mlx_loop(cub3d.game.mlx);
	ft_destroy_mlx(&cub3d.game);
	return (EXIT_FAILURE);
}
