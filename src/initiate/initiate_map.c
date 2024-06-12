/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:04:58 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/04 17:13:57 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// char	**set_map(char **map, int w, int h)
// {
// 	char	**new;

// 	new = format_map(map, w);
// 	check_player(new);
// 	check_borders(new);
// 	check_zero(new, w, h);
// 	return (new);
// }

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

int	double_array_len(char **arr)
{
	int	len;

	len = 0;
	while (*arr)
	{
		arr++;
		len++;
	}
	return (len);
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

int	is_map(char *line)
{
	while (*line)
	{
		if (!is_allowed_all(*line))
			return (0);
		line++;
	}
	return (1);
}

int	is_empty(char *line)
{
	if (ft_strlen(line) == 0)
		return (1);
	return (0);
}

void	file_error(char **to_clean, t_map *map)
{
	free_double_array(to_clean);
	perror("Error\nFile error\n");
	free_t_map(map);
	exit (1);
}

int	check_map(char **cur_map, t_map *map)
{
	char	**new;
	int		ret;

	ret = 1;
	map->width = count_colum(cur_map);
	map->height = count_lines(cur_map);
	new = format_map(cur_map, map->width);
	ret = check_player(new) && check_borders(new) \
		&& check_zero(new, map->width, map->height);
	map->map = new;
	if (new == NULL)
		return (0);
	return (ret);
}

void	create_map(t_map *map, int fd)
{
	char	**arr_file;
	char	*str_file;
	char	**c_map;
	int		i;

	map_init(map);
	str_file = ft_read_from_file(fd, NULL);
	arr_file = ft_split(str_file, '\n');
	free(str_file);
	i = 0;
	while (arr_file[i])
	{
		if (is_fc(arr_file[i]))
			set_fc(map, arr_file[i]);
		else if (is_texture(arr_file[i]))
			set_texture(map, arr_file[i]);
		else if (is_map(arr_file[i]))
			break ;
		else if (is_empty(arr_file[i]))
			;
		else
			file_error(arr_file, map);
		i++;
	}
	c_map = &(arr_file[i]);
	if (!check_map(c_map, map))
		file_error(arr_file, map);
	free_double_array(arr_file);
	set_player_pos(&map);
}
