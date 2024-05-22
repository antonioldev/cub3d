/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:58:05 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:46:48 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*s2;

	i = 0;
	len = ft_strlen((char *)s);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
