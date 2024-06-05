/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/05 12:21:26 by rtavabil         ###   ########.fr       */
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
	create_map(&(cub3d->map), fd);
	//output_tmap(&(cub3d->map));
	cub3d->game = initiate_mlx();
	cub3d->p = initiate_player(cub3d->map);
	cub3d->ray = initiate_ray(cub3d->p);
	load_texture(&cub3d->textures[NORTH], &cub3d->game, cub3d->map.no, NORTH);
	load_texture(&cub3d->textures[SOUTH], &cub3d->game, cub3d->map.so, SOUTH);
	load_texture(&cub3d->textures[WEST], &cub3d->game, cub3d->map.we, WEST);
	load_texture(&cub3d->textures[EAST], &cub3d->game, cub3d->map.ea, EAST);
}

void	free_t_map(t_map *map)
{
	if (map->no != NULL)
		free(map->no);
	if (map->so != NULL)
		free(map->so);
	if (map->we != NULL)
		free(map->we);
	if (map->ea != NULL)
		free(map->ea);
	if (map->map != NULL)
		free_double_array(map->map);
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
	ft_destroy_mlx(&cub3d);
	free_t_map(&(cub3d.map));
	return (EXIT_SUCCESS);
}
