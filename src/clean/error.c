/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:03:19 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/24 15:42:01 by alimotta         ###   ########.fr       */
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
		exit (EXIT_FAILURE);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		errno = 2;
		perror("Error while reading the file\n");
		exit (EXIT_FAILURE);
	}
	return (fd);
}
