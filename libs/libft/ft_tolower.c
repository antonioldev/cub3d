/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:43:11 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:50:31 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*int	main()
{
	int	i;

	i = 0;
	char str[30] = "AzZaa Test foR toUPpeR";
	while (str[i])
	{
		str[i] =  ft_tolower(str[i]);
		i++;
	}
	printf("%s\n", str);
	return (0);
}*/
