/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:06:23 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/04 16:48:02 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim(const char *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_new_str(const char *s1, size_t start, size_t end)
{
	size_t	i;
	char	*str;

	if (end <= 0 || start >= ft_strlen((char *)s1))
		return (ft_strdup(""));
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (end - start + 1))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen((char *)s1) - 1;
	if (ft_strlen((char *)s1) == 0)
		return (ft_strdup(""));
	while (ft_trim(set, s1[i]))
		i++;
	while (ft_trim(set, s1[j]))
		j--;
	return (ft_new_str(s1, i, j));
}
/*int	main()
{
	char * s1 = "HelloPleaseTrimme!\t\t\t\n  \t\t\t\t  ";
	char * set = " \t\n";

	printf("%s\n", ft_strtrim(s1, set));
	return 0;
}*/
