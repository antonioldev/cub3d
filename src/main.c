/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 17:28:14 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*It assign all date to the main structure*/
void	load_data(t_cub3d *cub3d, int argc, char **argv)
{
	int	fd;

	if (!check_extension(argv[1]))
	{
		perror("Error\nExtension error\n");
		exit (1);
	}
	fd = ft_error(argc, argv);
	create_map(&cub3d->map, fd);
	cub3d->game = initiate_mlx();
	cub3d->p = initiate_player(cub3d->map);
	cub3d->ray = initiate_ray(cub3d->p);
	load_all_texture(cub3d);
	cub3d->map.map[1][32] = 'C';//testing
	cub3d->map.map[1][28] = 'C';
	cub3d->map.map[1][11] = 'C';
	cub3d->map.map[3][10] = 'C';
	cub3d->map.map[1][28] = 'D';//testing
	cub3d->map.map[2][10] = 'd';
	initiate_sprite(cub3d, 0, 0, 0);
	initiate_doors(cub3d, 0, 0, 0);
}

/*It keep rendering the map and minimap on display*/
int	refresh_win(t_cub3d *cub3d)
{
	check_for_input(cub3d, 0, 0);
	check_doors(cub3d, -1, 0);
	clear_mini_map(&cub3d->game);
	render_mini_map(cub3d);
	raycasting(cub3d);
	raycasting_door(cub3d, -1);
	render_sprite(cub3d, 0, 0);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win,
		cub3d->game.img.img, 0, 0);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win,
		cub3d->game.img_minimap.img, 0, HEIGHT);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	load_data(&cub3d, argc, argv);
	mlx_loop_hook(cub3d.game.mlx, refresh_win, &cub3d);
	mlx_hook(cub3d.game.win, 17, 1L << 0, x_pressed, &cub3d);
	mlx_hook(cub3d.game.win, 2, 1L << 0, key_press, &cub3d);
	mlx_hook(cub3d.game.win, 3, 1L << 1, key_release, &cub3d);
	mlx_hook(cub3d.game.win, ButtonPress, ButtonPressMask, mouse_press, &cub3d);
    mlx_hook(cub3d.game.win, ButtonRelease, ButtonReleaseMask, mouse_release, &cub3d);
	mlx_loop(cub3d.game.mlx);
	ft_destroy_mlx(&cub3d);
	return (EXIT_SUCCESS);
}
