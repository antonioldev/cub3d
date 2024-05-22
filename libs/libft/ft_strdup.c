/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:48:01 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:44:06 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] != '\0')
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int main()
{
	char test[50]= "Io sono originale";
	char * ptr1;
	char * ptr2;
	int len1;
	int len2;

	ptr1 = ft_strdup(test);
	ptr2 = strdup(test);
	len1 = strlen(ptr1);
	len2 = strlen(ptr2);
	printf("My string is %d bites\n%s\n",len1, ptr1);
	printf("Original string is %d bites\n%s\n",len2, ptr2);
	return (0);
}*/
