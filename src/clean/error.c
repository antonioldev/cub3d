/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:03:19 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/05 13:15:19 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2 [i]);
		i++;
	}
	return (0);
}

void	check_extension(char *filename)
{
	size_t	len;
	
	len = ft_strlen(filename);
	if (len < 4)
	{
		perror("Error\nExtension Error");
		exit (1);
	}
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
	{
		perror("Error\nExtension Error");
		exit (1);
	}
}

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
		exit (EXIT_FAILURE);
	else
	{
		check_extension(argv[1]);
		fd = open(argv[1], O_RDONLY);
	}
	if (fd == -1)
	{
		errno = 2;
		perror("Error while reading the file\n");
		exit (EXIT_FAILURE);
	}
	return (fd);
}
