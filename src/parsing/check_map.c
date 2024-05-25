/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:23:14 by rtavabil          #+#    #+#             */
/*   Updated: 2024/05/24 15:37:32 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_top(char *line)
{
	int	empty;

	if (line)
	{
		empty = 1;
		while (*line == ' ')
			line++;
		while (*line != '\0' && *line != ' ')
		{
			if (*line != '1')
				return (0);
			empty = 0;
			line++;
		}
		while (*line == ' ')
			line++;
		if (*line != '\0')
			return (0);
		if (*line == '\0' && empty)
			return (0);
		return (1);
	}
	return (0);
}

int	check_middle_in(char *line)
{
	int	empty;

	if (line)
	{
		empty = 1;
		while (*line == ' ')
			line++;
		while (*line != '\0' && *line != ' ')
		{
			if (*line != '1' && *line != '0')
				return (0);
			empty = 0;
			line++;
		}
		while (*line == ' ')
			line++;
		if (*line != '\0')
			return (0);
		if (*line == '\0' && empty)
			return (0);
		return (1);
	}
	return (0);
}

int	check_middle_edge(char *line)
{
	if (line)
	{
		while (*line == ' ')
			line++;
		if (*line != '1')
			return (0);
		while (*line != '\0' && *line != ' ')
			line++;
		if (*line != '\0' && *(line - 1) != '1')
			return (0);
		if (*line == '\0' && *(line - 1) != '1')
			return (0);
		return (1);
	}
	return (0);
}

int	check_middle(char *line)
{
	return (check_middle_in(line) && check_middle_edge(line));
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

// int	check_borders(char	**map)
// {
// 	int	i;
// 	int	lines;

// 	i = 1;
// 	lines = count_lines(map);
// 	while (i < lines - 1)
// 	{
// 		if (i == 0)
// 	}
// }