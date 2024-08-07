/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:31:27 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/19 10:34:25 by alimotta         ###   ########.fr       */
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
			|| c == 'S' || c == '1' || c == '0' \
			|| c == ' ' || c == 'D' || c == 'd' \
			|| c == 'C');
}
