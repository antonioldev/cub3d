/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:15:50 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/05 14:16:48 by rtavabil         ###   ########.fr       */
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

char *malloc_nl(int	*increment)
{
	char *newline;

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
	size_t	i;
	int		start;

	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return ((void *)0);
	i = 0;
	start = -1;
	while (i <= ft_strlen(s) && s[i] != '\0')
	{
		while (s[i] == c)
			*res++ = malloc_nl(&i);
		if (s[i] != c)
		{
			start = (int)i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (i - start > 0)
				*res++ = ft_substr(s, start, i - start);
		}	
	}
	*res = (void *)0;
	return (res - ft_count_words(s, c));
}

void	init_check(t_check *check)
{
	check->no = 0;
	check->so = 0;
	check->we = 0;
	check->ea = 0;
	check->f = 0;
	check->c = 0;
}

void	preparse_check(int fd)
{
	char	*str;
	char	**lines;
	int		i;
	t_check	check;

	init_check(&check);
	str = ft_read_from_file(fd, NULL);
	lines = ft_split_par(str, '\n');
	free(str);
	i = 0;
	while (lines[i])
	{
		if (is_fc(lines[i]))
			;
		else if (is_texture(lines[i]))
			set_texture(map, lines[i]);
		else if (is_map(lines[i]))
			break ;
		else if (is_empty(lines[i]))
			;
		else
			file_error(arr_file, map);
		i++;
	}
}