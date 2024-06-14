/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:26:22 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/14 16:29:39 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_middle(char *line)
{
	if (line)
	{
		if (!check_line_edge(line))
			return (0);
		while (*line == ' ')
			line++;
		while (*line)
		{
			if (!is_allowed_all(*line))
				return (0);
			line++;
		}
		return (1);
	}
	return (0);
}

int	is_allowed_all(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' \
			|| c == 'S' || c == '1' || c == '0' || c == ' ');
}
