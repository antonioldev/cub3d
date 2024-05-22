/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:37:39 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/04 10:09:53 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	if (!dest && !src)
		return (NULL);
	p_dest = (char *)dest;
	p_src = (char *)src;
	i = 0;
	if (p_dest > p_src)
		while (n-- > 0)
			p_dest[n] = p_src[n];
	else
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}
/*int	main()
{
	char a[25]="hare rama hare rama";

  	char b[25]="hare rama hare rama";

  	memmove(a+5,a,20);
  	puts(a);
  	ft_memmove(b+5,b,20);
  	puts(b);
	return (0);
}*/
