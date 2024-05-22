/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:30:20 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 10:12:44 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p_dest;
	unsigned const char	*p_src;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	i = 0;
	p_dest = dest;
	p_src = src;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
/*int main()
{
  char a[1];
  char b[25]="xxxx xxxx xxxx xxxx";

   char a1[1];
  char b1[25]="xxxx xxxx xxxx xxxx";
  memcpy(a1,b1,1);
  printf("%s ", a1);

  ft_memcpy(a,b,1);
  printf("\n%s MY", a);
}*/
