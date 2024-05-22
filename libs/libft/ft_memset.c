/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:04 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:40:33 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}
/*int	main()
{
	char test[50] = "This is string.h library function";
	char test2[50] = "This is string.h library function";

	ft_memset(test, '$', 7);
	printf("%s\n", test);
	memset(test2, '$', 7);
        printf("%s\n", test2);
	return 0;
}*/
