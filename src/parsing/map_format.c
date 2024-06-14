/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:01:17 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/13 16:41:53 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*fill_string(char *to_copy, int w, char **map)
{
	int		i;
	char	*new;

	printf("width = %d, len to_copy = %d\n", w, (int)ft_strlen(to_copy));
	new = (char *)malloc((w + 1) * sizeof(char));
	if (!new)
	{
		free_double_array(map);
		perror("Malloc error\n");
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
	printf("num of lines = %d\n", lines);
	new = (char **)malloc((lines + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < lines)
	{
        printf("Processing line %d = %s\n", i, map[i]);  // Print current line for debugging
        new[i] = fill_string(map[i], w, map);
        printf("Formatted line %d = '%s'\n", i, new[i]);
		i++;
	}
	new[lines] = NULL;
	return (new);
}
