/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:39:06 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:50:52 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*int	main()
{
	int	i;

	i = 0;
	char str[50] = "Test foR toUPpeR ! ! 2! HeeL";
	while (str[i])
	{
		str[i] =  ft_toupper(str[i]);
		i++;
	}
	printf("%s\n", str);
	return (0);
}*/
