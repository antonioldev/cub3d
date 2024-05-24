/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:35:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/23 18:05:33 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	char	**c_map;

	fd = ft_error(argc, argv);
	map_init(&map, fd);
	printf("map.f[1] = %d\n", map.f[1]);
	c_map = map.map;
	while (*c_map)
	{
		printf("%s\n", *c_map);
		c_map++;
	}
	return (0);
}
