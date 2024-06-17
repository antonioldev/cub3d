/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:20:58 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/12 17:51:48 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static size_t	ft_count_words_par(char const *s, char c)
{
	size_t	words;
	size_t	flag;

	words = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (*s == c)
		{
			flag = 0;
			words++;
		}
		s++;
	}
	return (words);
}

char	*malloc_nl(int	*increment)
{
	char	*newline;

	newline = (char *)malloc(2 * sizeof(char));
	if (!newline)
		return (NULL);
	newline[0] = '\n';
	newline[1] = '\0';
	increment++;
	return (newline);
}

char	**ft_split_par(char const *s, char c)
{
	char	**res;
	int		i;
	int		start;

	res = (char **)malloc((ft_count_words_par(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return ((void *)0);
	i = 0;
	start = -1;
	while (i <= (int)ft_strlen(s) && s[i] != '\0')
	{
		if (s[i] == c)
		{
			*res++ = malloc_nl(&i);
			i++;
		}
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (i - start > 0)
				*res++ = ft_substr(s, start, i - start);
		}
	}
	*res = (void *)0;
	return (res - ft_count_words_par(s, c));
}

void	init_check(t_check *check)
{
	check->no = 0;
	check->so = 0;
	check->we = 0;
	check->ea = 0;
	check->f = 0;
	check->c = 0;
	check->map = 0;
}

void	preparse_check(char *str)
{
	char	**lines;
	int		i;
	t_check	check;
	char	**c_map;

	init_check(&check);
	lines = ft_split_par(str, '\n');
	i = 0;
	while (lines[i])
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
		i++;
	}
	c_map = lines + i;
	i = 1;
	while (c_map[i])
	{
		if (!ft_strncmp(c_map[i - 1], "\n", ft_strlen(c_map[i])) && !ft_strncmp(c_map[i], "\n", ft_strlen(c_map[i])))
		{
			if (check.map != -2)
				check.map = -1;
		}
		if (ft_strncmp(c_map[i], "\n", ft_strlen(c_map[i])) != 0 && check.map < 0)
			check.map = -2;
		i++;
	}
	free_double_array(lines);
	printf("no = %d so = %d we = %d ea = %d f = %d c = %d map = %d\n", check.no, check.so, check.we, check.ea, check.f, check.c, check.map);
	if ((check.no != 1) || (check.so != 1) || (check.we != 1) || (check.ea != 1) || (check.f != 1) || (check.c != 1) || (check.map == -2))
	{
		free(str);
		perror("Error\nPreparse error\n");
		exit (1);
	}
}
