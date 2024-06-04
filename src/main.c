/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/04 16:59:46 by rtavabil         ###   ########.fr       */
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

	printf("Floor colour: %x\n", map->f);
	printf("Ceiling colour: %x\n", map->c);

	printf("Player position x: %d, y: %d, orientation: %c\n", map->x, map->y, map->player_orientation);

	printf("Map width: %d, height: %d\n", map->width, map->height);

	copy_map = map->map;
	while (*copy_map)
	{
		printf("|%s|\n", *copy_map);
		copy_map++;
	}
}

void	load_data(t_cub3d *cub3d, int argc, char **argv)
{
	int	fd;

	fd = ft_error(argc, argv);
	create_map(&(cub3d->map), fd);
	output_tmap(&(cub3d->map));
	// cub3d->game = initiate_mlx();
	// cub3d->v = initiate_player(cub3d->map);
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
	// mlx_loop_hook(cub3d.game.mlx, render_map, &cub3d);
	// mlx_hook(cub3d.game.win, 17, 1L << 0, x_pressed, &cub3d);
	// mlx_hook(cub3d.game.win, 3, 1L << 1, handle_input, &cub3d);
	// mlx_loop(cub3d.game.mlx);
	// ft_destroy_mlx(&cub3d.game);
	free_t_map(&(cub3d.map));
	return (EXIT_SUCCESS);
}
