/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:51:37 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/19 08:36:47 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_texture(char *texture)
{
	int		fd;
	int		bytes;
	char	buffer[4];

	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes = read(fd, buffer, sizeof(buffer));
	close(fd);
	if (bytes == -1)
		return (0);
	return (1);
}

int	is_texture(char *line, t_check *check)
{
	if (check != NULL)
	{
		if (!ft_strncmp(line, "NO", 2))
			return (check->no++, 1);
		if (!ft_strncmp(line, "SO", 2))
			return (check->so++, 1);
		if (!ft_strncmp(line, "WE", 2))
			return (check->we++, 1);
		if (!ft_strncmp(line, "EA", 2))
			return (check->ea++, 1);
	}
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) \
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (check_texture(line + 3));
	return (0);
}

void	set_texture(t_map *map, char *texture)
{
	if (!ft_strncmp(texture, "NO", 2))
		map->no = ft_strdup(texture + 3);
	if (!ft_strncmp(texture, "SO", 2))
		map->so = ft_strdup(texture + 3);
	if (!ft_strncmp(texture, "WE", 2))
		map->we = ft_strdup(texture + 3);
	if (!ft_strncmp(texture, "EA", 2))
		map->ea = ft_strdup(texture + 3);
}
