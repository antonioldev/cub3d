/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:42:58 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/22 14:10:09 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (start >= ft_strlen (s))
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
		return (substr);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return ((void *)0);
	i = 0;
	while (i < (unsigned int)len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*int main()
{
	char s[] = "lorem ipsum dolor sit amet";
	printf("%s\n", ft_substr("hola", 4294967295, 5));
	//printf("%s\n", substr(s, 2, 3));
	return (0);

}*/
