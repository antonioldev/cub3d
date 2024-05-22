/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:38:14 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:39:26 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*p_s;
	unsigned char		p_c;

	i = 0;
	p_s = (unsigned char *)s;
	p_c = (unsigned char)c;
	while (i < n)
	{
		if (p_s[i] == p_c)
			return ((void *)&p_s[i]);
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char test[50] = "Ciao test my_function";
        char test2[50] = "Ciao test or_function";
	const char ch = 't';
	char * ret;
	char * ret2;

        ret = ft_memchr(test, ch, 16);
	puts(ret);
        ret2 = memchr (test2, ch, 16);
	printf("%s\n",ret2);
        return 0;
}*/
