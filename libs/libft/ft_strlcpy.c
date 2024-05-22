/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:01:26 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:45:51 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (src_len + 1 < size)
	{
		while (i < src_len + 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (size != 0)
	{
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[size - 1] = '\0';
	}
	return (src_len);
}
/*int	main()
{
	char dest[30] = "dst_dst_dst";
	const char src[40] = "src_src_src_src_";
	int n;

	n = ft_strlcpy(dest, src, 4);
	printf("Copiato %d bytes, %s\n", n, dest);

	char  dest2[30] = "dst_dst_dst";
        const char src2[40] = "src_src_src_src_";

        n = strlcpy(dest2, src2, 4);
        printf("Copiato %d bytes, %sORIGINAL\n", n, dest2);
	return 0;
}*/
