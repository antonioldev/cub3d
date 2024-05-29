/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:04:58 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/29 13:19:30 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**set_map(char **map, int w, int h)
{
	char	**new;

	new = format_map(map, w);
	check_player(new);
	check_borders(new);
	check_zero(new, w, h);
	return (new);
}

void	set_player_pos(t_map **map)
{
	char	**c_map;
	int		i;
	int		j;

	c_map = (*map)->map;
	i = 1;
	while (i < (*map)->height - 1)
	{
		j = 1;
		while (j < (*map)->width - 1)
		{
			if (is_allowed_p((c_map[i][j])))
			{
				(*map)->x = j;
				(*map)->y = i;
				(*map)->player_orientation = c_map[i][j];
			}
			j++;
		}
		i++;
	}
}
//initialing map structure
void	map_init(t_map *map, int fd)
{
	char	*str;

	str = ft_read_from_file(fd, NULL);
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = ft_split(str, '\n');
	free(str);
	map->width = count_colum(map->map);
	map->height = count_lines(map->map);
	map->map = set_map(map->map, map->width, map->height);
	set_player_pos(&map);
}

