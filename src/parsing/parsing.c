/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:12:16 by rtavabil          #+#    #+#             */
/*   Updated: 2024/05/22 18:18:00 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//checks number of arguments (should only be 1 argument)
//checks if file opened correctly
int	ft_error(int argc, char **argv)
{
	int	fd;

	errno = 22;
	if (argc < 2)
		perror("Error: Map was not provided");
	else if (argc > 2)
	{
		errno = 7;
		perror("Error");
	}
	if (argc != 2)
		exit (1);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		errno = 2;
		perror("Error while reading the file\n");
		exit (1);
	}
	return (fd);
}

//reads the whole map from the file
char	*ft_read_from_file(int fd, char *s)
{
	size_t	bytes_read;
	char	temp[1];
	char	*s2;

	while (s == 0 || bytes_read > 0)
	{
		bytes_read = read(fd, temp, 1);
		if (s == 0 && bytes_read > 0)
		{
			s = (char *)malloc(bytes_read + 1);
			ft_strlcpy(s, temp, bytes_read + 1);
		}
		else if (bytes_read > 0)
		{
			s2 = (char *)malloc(ft_strlen(s) + bytes_read + 1);
			ft_strlcpy(s2, s, ft_strlen(s) + 1);
			ft_strlcat(s2, temp, ft_strlen(s) + bytes_read + 1);
			free (s);
			s = (char *)malloc(ft_strlen(s2) + 1);
			ft_strlcpy(s, s2, ft_strlen(s2) + 1);
			free (s2);
		}
	}
	return (s);
}

//initialing map structure
void	map_init(t_map *map, int fd)
{
	char	*str;

	str = ft_read_from_file(fd, NULL);
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->c[0] = -1;
	map->c[1] = -1;
	map->c[2] = -1;
	map->f[0] = -1;
	map->f[1] = -1;
	map->f[2] = -1;
	map->map = ft_split(str, '\n');
}
