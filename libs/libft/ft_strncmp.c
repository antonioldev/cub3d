/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:32:13 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:47:26 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2 [i]);
		i++;
	}
	return (0);
}
/*int main()
{
	int i;
	int j;

	char * s2 = "ABCdef";
	char * s1 = "ABCDEF";
	i = strncmp(s1, s2, 4);
	j = ft_strncmp(s1, s2, 4);
	printf("Original gives %d, my function return %d\n", i, j);
	return 0;
}*/
