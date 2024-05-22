/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/22 17:01:35 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	t_mlx game;
	t_map map;

	initiate_mlx(&game, &map);
	render_mini_map(game, map);
	mlx_hook(game.win, 17, 1L << 0, x_pressed, &game);
	
	//mlx_hook(game.win, 3, 1L << 1, handle_input, &v);
	mlx_loop(game.mlx);
	ft_destroy_mlx(&game);
	return (EXIT_FAILURE);
}