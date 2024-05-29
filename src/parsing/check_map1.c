/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:14:59 by rtavabil          #+#    #+#             */
/*   Updated: 2024/05/29 14:43:17 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_colum(char **map)
{
	int	i;

	i = 0;
	while (*map)
	{
		if ((int)ft_strlen(*map) > i)
			i = (int)ft_strlen(*map);
		map++;
	}
	return (i);
}

int	count_lines(char **map)
{
	int	lines;

	lines = 0;
	while (*map)
	{
		map++;
		lines++;
	}
	return (lines);
}

int	check_spaces(char **map, int i, int j)
{
	if (map[i - 1][j - 1] == ' ')
		return (0);
	if (map[i - 1][j] == ' ')
		return (0);
	if (map[i - 1][j + 1] == ' ')
		return (0);
	if (map[i][j - 1] == ' ')
		return (0);
	if (map[i][j + 1] == ' ')
		return (0);
	if (map[i + 1][j - 1] == ' ')
		return (0);
	if (map[i + 1][j] == ' ')
		return (0);
	if (map[i + 1][j + 1] == ' ')
		return (0);
	return (1);
}

int	check_zero(char **map, int w, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i < h - 1)
	{
		j = 0;
		while (j < w - 1)
		{
			if (map[i][j] == '0')
				if (!check_spaces(map, i, j))
					parsing_error(map, "Error\nMap Error\n");
			j++;
		}
		i++;
	}
	return (1);
}

int	check_space(char *line)
{
	if (line)
	{
		while (*line)
		{
			if (*line == 0 && (*(line + 1) == ' '))
				return (0);
			else if (*line == ' ' && (*(line + 1) == '0'))
				return (0);
			line++;
		}
		return (1);
	}
	return (0);
}
