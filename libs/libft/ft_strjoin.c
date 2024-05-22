/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:53:17 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:44:45 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s3;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	s3 = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, s1_len + 1);
	ft_strlcat(s3, s2, s1_len + s2_len + 1);
	return (s3);
}
/*int main()
{
	const char s1[20] = "Ciao Mi";
	const char s2[20] = "Chiamo Antonio!";
	printf("\n%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
