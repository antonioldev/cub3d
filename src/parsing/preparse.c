/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:20:58 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/19 10:12:46 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_c_map(char **c_map, t_check *check)
{
	int	i;

	i = 1;
	while (c_map[i])
	{
		if (!ft_strncmp(c_map[i - 1], "\n", ft_strlen(c_map[i]))
			&& !ft_strncmp(c_map[i], "\n", ft_strlen(c_map[i])))
		{
			if (check->map != -2)
				check->map = -1;
		}
		if (ft_strncmp(c_map[i], "\n", ft_strlen(c_map[i])) != 0
			&& check->map < 0)
			check->map = -2;
		i++;
	}
}

static void	check_c_map2(t_check *check, char **str)
{
	if ((check->no != 1) || (check->so != 1) || (check->we != 1)
		|| (check->ea != 1) || (check->f != 1) || (check->c != 1)
		|| (check->map == -2))
	{
		free(*str);
		perror("Error\nPreparse error\n");
		exit (1);
	}
}

void	preparse_check(char *str, int i)
{
	char	**lines;
	t_check	check;
	char	**c_map;

	init_check(&check);
	lines = ft_split_par(str, '\n', 0);
	while (lines[++i])
	{
		if (is_fc(lines[i], &check))
			;
		else if (is_texture(lines[i], &check))
			;
		else if (is_map(lines[i]))
			break ;
		else if (is_empty(lines[i]))
			;
		else if (!ft_strncmp(lines[i], "\n", ft_strlen(lines[i])))
			;
		else
			check.map = -2;
	}
	c_map = lines + i;
	check_c_map(c_map, &check);//
	free_double_array(lines);
	check_c_map2(&check, &str);//
}
