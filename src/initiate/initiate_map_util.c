/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:39:10 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/19 08:40:58 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
