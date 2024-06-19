/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:03:19 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/19 13:50:42 by rtavabil         ###   ########.fr       */
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
		ft_putstr_fd("Error\nMap was not provided\n", 2);
	else if (argc > 2)
		ft_putstr_fd("Error\nToo many arguments\n", 2);
	if (argc != 2)
		exit (EXIT_FAILURE);
	else
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nError while reading the file\n", 2);
		exit (EXIT_FAILURE);
	}
	return (fd);
}

void	file_error(char **to_clean, t_map *map)
{
	free_double_array(to_clean);
	ft_putstr_fd("Error\nMisconfiguration in the input file\n", 2);
	free_t_map(map);
	exit (1);
}

void	ft_error_empty_map(void)
{
	ft_putstr_fd("Error\nEmpty map\n", 2);
	exit (1);
}
