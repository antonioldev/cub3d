/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:20:58 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/19 14:36:14 by rtavabil         ###   ########.fr       */
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
		ft_putstr_fd("Error\nMisconfiguration in the input file\n", 2);
		exit (1);
	}
}

void	preparse_check(char *str, int i)
{
	char	**l;
	t_check	check;
	char	**c_map;

	init_check(&check);
	l = ft_split_par(str, '\n', 0);
	if (l == NULL)
	{
		free(str);
		exit (1);
	}
	while (l[++i])
	{
		if (is_fc(l[i], &check) || is_texture(l[i], &check)
			|| is_empty(l[i]) || !ft_strncmp(l[i], "\n", ft_strlen(l[i])))
			;
		else if (is_map(l[i]))
			break ;
		else
			check.map = -2;
	}
	c_map = l + i;
	check_c_map(c_map, &check);
	free_double_array(l);
	check_c_map2(&check, &str);
}
