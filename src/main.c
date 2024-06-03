/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/03 16:32:17 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	output_tmap(t_map *map)
{
	char	**copy_map;

	printf("North texture: %s\n", map->no);
	printf("South texture: %s\n", map->so);
	printf("West texture: %s\n", map->we);
	printf("East texture: %s\n", map->ea);

	printf("Floor colour: %u\n", map->f);
	printf("Ceiling colour: %u\n", map->c);

	printf("Player position x: %d, y: %d, orientation: %d\n", map->x, map->y, map->player_orientation);

	printf("Map width: %d, height: %d\n", map->width, map->height);

	copy_map = map->map;
	while (*copy_map)
	{
		printf("|%s|\n", *copy_map);
		copy_map++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_cub3d	cub3d;

	fd = ft_error(argc, argv);
	map_init(&cub3d.map, fd);
	// cub3d.game = initiate_mlx(&cub3d.map);
	// mlx_hook(cub3d.game.win, 17, 1L << 0, x_pressed, &cub3d);
	// mlx_hook(cub3d.game.win, 3, 1L << 1, handle_input, &cub3d);
	// mlx_loop_hook(cub3d.game.mlx, render_mini_map, &cub3d);
	// mlx_loop(cub3d.game.mlx);
	ft_destroy_mlx(&cub3d.game);
	return (EXIT_FAILURE);
}
