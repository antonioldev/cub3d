/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:49:44 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:47:56 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && (i + j < len))
		{
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*int	main()
{
	const char * big = "Foo Bar Baz";
	const char * little = "Ba";
	char * ptr;

	const char * big2 = "Foo Bar Baz";
        char * ptr2;
	ptr2 = ft_strnstr(big2, little, 10);
	printf("%s\n", ptr2);
	printf("ORIGINAL\n");
	ptr = strnstr(big, little, 10);
	printf("%s\n", ptr);
	return (0);
}*/
