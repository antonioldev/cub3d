/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:23:14 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/13 18:29:32 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_line_edge(char *line)
{
	int	len;
	int	i;

	i = 0;
	if (line)
	{
		len = (int)ft_strlen(line) - 1;
		while (line[i] == ' ')
			i++;
		if (line[i] != '1')
			return (0);
		while (line[len] == ' ')
			len--;
		if (line[len] != '1')
			return (0);
		return (1);
	}
	return (0);
}

int	check_top(char *line)
{
	if (line)
	{
		if (!check_line_edge(line))
			return (0);
		while (*line == ' ')
			line++;
		while (*line)
		{
			if (*line != '1' && *line != ' ')
				return (0);
			line++;
		}
		return (1);
	}
	return (0);
}

int	check_player(char **map)
{
	int		flag;
	char	*line;

	if (*map)
	{
		flag = 0;
		while (*map != NULL)
		{
			line = *map;
			while (*line)
			{
				if (is_allowed_p(*line) && !flag)
					flag = 1;
				else if (is_allowed_p(*line) && flag)
					return (0);
				line++;
			}
			map++;
		}
		if (!flag)
			return (0);
	}
	return (1);
}

int	check_borders(char	**map)
{
	int	i;
	int	lines;

	if (!check_top(map[0]))
		return (0);
	i = 1;
	lines = count_lines(map);
	while (i < lines - 1)
	{
		if (!check_middle(map[i]))
			return (0);
		i++;
	}
	if (!check_top(map[lines - 1]))
		return (0);
	return (1);
}
