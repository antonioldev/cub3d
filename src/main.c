/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/05 15:56:54 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	output_tmap(t_map *map)
// {
// 	char	**copy_map;

// 	printf("North texture: %s\n", map->no);
// 	printf("South texture: %s\n", map->so);
// 	printf("West texture: %s\n", map->we);
// 	printf("East texture: %s\n", map->ea);

// 	printf("Floor colour: %x\n", map->f);
// 	printf("Ceiling colour: %x\n", map->c);

// 	printf("Player position x: %d, y: %d, orientation: %c\n", map->x, map->y, map->player_orientation);

// 	printf("Map width: %d, height: %d\n", map->width, map->height);

// 	copy_map = map->map;
// 	while (*copy_map)
// 	{
// 		printf("|%s|\n", *copy_map);
// 		copy_map++;
// 	}
// }

/*It assign all date to the main structure*/
void	load_data(t_cub3d *cub3d, int argc, char **argv)
{
	int	fd;
	int	i;

	fd = ft_error(argc, argv);
	create_map(&cub3d->map, fd);
	cub3d->game = initiate_mlx();
	cub3d->p = initiate_player(cub3d->map);
	cub3d->ray = initiate_ray(cub3d->p);
	load_texture(&cub3d->textures[NORTH], &cub3d->game, "./texture/wall_N.xpm", NORTH);
	load_texture(&cub3d->textures[SOUTH], &cub3d->game, "./texture/wall_S.xpm", SOUTH);
	load_texture(&cub3d->textures[WEST], &cub3d->game, "./texture/wall_W.xpm", WEST);
	load_texture(&cub3d->textures[EAST], &cub3d->game, "./texture/wall_E.xpm", EAST);
}

int	mouse_hook(t_cub3d *cub3d)
{
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	load_data(&cub3d, argc, argv);
	mlx_loop_hook(cub3d.game.mlx, refresh_win, &cub3d);
	mlx_hook(cub3d.game.win, 17, 1L << 0, x_pressed, &cub3d);
	mlx_hook(cub3d.game.win, 2, 1L << 0, key_press, &cub3d);
	mlx_hook(cub3d.game.win, 3, 1L << 1, key_release, &cub3d);
	mlx_mouse_hook(cub3d.game.win, mouse_hook, &cub3d);
	mlx_loop(cub3d.game.mlx);
	ft_destroy_mlx(&cub3d);
	return (EXIT_SUCCESS);
}
