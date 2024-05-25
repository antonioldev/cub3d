/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:04:58 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 15:40:41 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//initialing map structure
void	map_init(t_map *map, int fd)
{
	char	*str;

	str = ft_read_from_file(fd, NULL);
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->c[0] = -1;
	map->c[1] = -1;
	map->c[2] = -1;
	map->f[0] = -1;
	map->f[1] = -1;
	map->f[2] = -1;
	map->map = ft_split(str, '\n');
	//TESTING
	//The following are used for testing, we should get those in the parser
	map->x = 1;
	map->y = 1;
	map->width = 70;
	map->height = 26;
}