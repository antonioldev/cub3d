/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:02:34 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/04 16:47:36 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
/*int 	main()
{
	char * s = "CiaoY mi chiamo Antonio";
	char c = 'a';
	char *j ;
	char *y;
	j = strchr (s, c);
	if (j)
		printf("%p\n",  j);
	y = ft_strchr(s, c);
	if (y)
		printf("%p\n", y);
	return (0);


}*/
