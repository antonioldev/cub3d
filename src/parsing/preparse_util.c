/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:11:24 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/19 09:15:28 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

char	**ft_split_par(char const *s, char c, int i)
{
	char	**res;
	int		start;

	res = (char **)malloc((ft_count_words_par(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return ((void *)0);
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
