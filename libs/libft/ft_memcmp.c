/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:04:42 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:39:56 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*int main ()
{
   char str1[15];
   char str2[15];
   int ret;
   int ret2;

   memcpy(str1, "ABCDEF", 6);
   memcpy(str2, "ABCDEF", 6);
   ret = memcmp(str1, str2, 8);
   ret2 = ft_memcmp(str1, str2, 8);
   printf ("%d = %d", ret, ret2);
   return (0);
}*/
