/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:01:17 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/19 14:13:34 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*fill_string(char *to_copy, int w, char **map)
{
	int		i;
	char	*new;

	new = (char *)malloc((w + 1) * sizeof(char));
	if (!new)
	{
		free_double_array(map);
		ft_putstr_fd("Error\nMalloc error\n", 2);
		exit(1);
	}
	i = 0;
	while (i < w)
	{
		if (i < (int)ft_strlen(to_copy))
			new[i] = to_copy[i];
		else
			new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**format_map(char **map, int w)
{
	char	**new;
	int		lines;
	int		i;

	lines = count_lines(map);
	new = (char **)malloc((lines + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		new[i] = fill_string(map[i], w, map);
		i++;
	}
	new[lines] = NULL;
	return (new);
}
