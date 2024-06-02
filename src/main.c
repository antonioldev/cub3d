/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/02 08:21:05 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*It assign all date to the main structure*/
void	load_data(t_cub3d *cub3d, int argc, char **argv)
{
	int	fd;

	fd = ft_error(argc, argv);
	map_init(&cub3d->map, fd);
	cub3d->game = initiate_mlx();
	cub3d->p = initiate_player(cub3d->map);
	cub3d->ray = initiate_ray();
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	load_data(&cub3d, argc, argv);
	mlx_loop_hook(cub3d.game.mlx, refresh_win, &cub3d);
	mlx_hook(cub3d.game.win, 17, 1L << 0, x_pressed, &cub3d);
	mlx_hook(cub3d.game.win, 2, 1L << 0, key_press, &cub3d);
	mlx_hook(cub3d.game.win, 3, 1L << 1, key_release, &cub3d);
	mlx_loop(cub3d.game.mlx);
	ft_destroy_mlx(&cub3d.game);
	return (EXIT_SUCCESS);
}
