/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:04:58 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/19 13:54:59 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
void	map_init(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->c = 0xE0FFFF;
	map->f = 0x808080;
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->map = 0;
	map->x = 0;
	map->y = 0;
}

int	check_map(char **cur_map, t_map *map)
{
	char	**new;
	int		ret;

	ret = 1;
	map->width = count_colum(cur_map);
	map->height = count_lines(cur_map);
	new = format_map(cur_map, map->width);
	if (new == NULL)
		return (0);
	ret = check_player(new) && check_borders(new) \
		&& check_zero(new, map->width, map->height);
	map->map = new;
	return (ret);
}

void	check_array(t_map *map, char **arr_file, char ***c_map)
{
	int	i;

	i = 0;
	while (arr_file[i])
	{
		if (is_fc(arr_file[i], NULL))
			set_fc(map, arr_file[i]);
		else if (is_texture(arr_file[i], NULL))
			set_texture(map, arr_file[i]);
		else if (is_map(arr_file[i]))
			break ;
		else if (is_empty(arr_file[i]))
			;
		else
			file_error(arr_file, map);
		i++;
	}
	*c_map = &(arr_file[i]);
}

void	create_map(t_map *map, int fd)
{
	char	**arr_file;
	char	*str_file;
	char	**c_map;

	map_init(map);
	str_file = ft_read_from_file(fd, NULL, 0);
	preparse_check(str_file, -1);
	arr_file = ft_split(str_file, '\n');
	free(str_file);
	check_array(map, arr_file, &c_map);
	if (!check_map(c_map, map))
		file_error(arr_file, map);
	free_double_array(arr_file);
	set_player_pos(&map);
}
