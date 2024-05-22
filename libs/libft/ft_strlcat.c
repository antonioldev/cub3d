/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:17:04 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:45:17 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	if ((!dest || !src) && !size)
		return (0);
	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen((char *)dest);
	if (dest_len >= size)
		dest_len = size;
	if (size <= dest_len)
		return (dest_len + src_len);
	if (src_len < size - dest_len)
		ft_memcpy(dest + dest_len, (char *)src, src_len + 1);
	else
		ft_memcpy(dest + dest_len, (char *)src, size - dest_len - 1);
	dest[size - 1] = '\0';
	return (dest_len + src_len);
}
/*int	main()
{
	char dest[30] = "000000";
	const char src[30] = "abcd";
	char dest2[] = "000000";
        const char src2[] = "abcd";
	int	n;
	int	n2;

	n = ft_strlcat(dest, src, 4);
	printf("%d copiati, %s \n", n,dest);
	printf("\nORIGINAL:\n");
	n2 = strlcat(dest2, src2, 4);
        printf("%d copiati, %s \n", n2,dest2);
	return 0;
}*/
