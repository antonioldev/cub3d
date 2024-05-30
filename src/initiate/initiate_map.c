/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:04:58 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/30 17:41:03 by rtavabil         ###   ########.fr       */
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
void	put_map(t_map *map, char **c_map)
{
	map->map = c_map;
	map->width = count_colum(map->map);
	map->height = count_lines(map->map);
	map->map = set_map(map->map, map->width, map->height);
	set_player_pos(&map);
}

char	*check_arg(char *filename)
{
	if (filename == NULL)
		return (NULL);
	else
	{
		if (access(filename, F_OK | R_OK) == -1) //TODO change access() to open()
			return (NULL);
		else
			return (filename);
	}
	return (NULL);
}

int	check_num(char *num)
{
	int	number;
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (-1);
		i++;
	}
	if (i  > 3)
		return (-1);
	number = ft_atoi(num);
	if (num < 0 || num > 255)
		return (-1);
	return (number);
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

int	check_rgb(char *rgb, int arr[3])
{
	char	**num;

	num = ft_split(rgb, ',');
	if (double_array_len(num) != 3)
	{

	}
}

int	file_line_map(char **temp_line, t_map *map)
{
	if (!ft_strncmp(temp_line[0], "F", 2))
	{
		if (check_rgb(temp_line[1], map->f) == -1)
			return (-1);
	}
	if (!ft_strncmp(temp_line[0], "C", 2))
	{
		if (check_rgb(temp_line[1], map->c) == -1)
			return (-1);
	}
	return (1);
}

int	file_line(char **temp_line, t_map *map)
{
	if (!ft_strncmp(temp_line[0], "NO", 3))
	{
		map->no = check_arg(temp_line[1]);
		if (map->no == NULL)
			return (-1);
	}
	if (!ft_strncmp(temp_line[0], "SO", 3))
	{
		map->so = check_arg(temp_line[1]);
		if (map->so == NULL)
			return (-1);
	}
	if (!ft_strncmp(temp_line[0], "WE", 3))
	{
		map->we = check_arg(temp_line[1]);
		if (map->we == NULL)
			return (-1);
	}
	if (!ft_strncmp(temp_line[0], "EA", 3))
	{
		map->ea = check_arg(temp_line[1]);
		if (map->ea == NULL)
			return (-1);
	}
	else 
		return (file_line_map(temp_line, map));
	return (1);
}

char	**read_file(t_map *map, int fd)
{
	char	*str;
	char	**temp;
	char	**temp_line;
	int		i;

	str = ft_read_from_file(fd, NULL);
	temp = ft_split(str, '\n');
	free(str);
	i = 0;
	while (temp[i])
	{
		temp_line = ft_split(temp[i], ' ');
		if (file_line(temp_line, map) < 0)
		{
			free_double_array(temp);
			free_double_array(temp_line);
			perror("Error\nArgs error\n");
			exit (1);
		}
	}
}

void	create_map(t_map *map, int fd)
{
	char	**c_map;

	map_init(map);
	c_map = read_file(map, fd);
	put_map(map, c_map);
}

void	map_init(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->c = 0; //set to default
	map->f = 0; //set to default
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->map = 0;
	map->x = 0;
	map->y = 0;
}