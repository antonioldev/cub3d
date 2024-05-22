/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:50:25 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:46:12 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*int main () {
   char str[50] = "This is test of the string";
   int len;

   len = 0;
   len = ft_strlen(str);
   printf("Length of |%s| is |%d|\n", str, len);

   return(0);
}*/
