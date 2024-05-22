/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:22:17 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:28:54 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 0;
	result = 0;
	while (*(nptr + i) == 32 || (*(nptr + i) >= 9 && *(nptr + i) <= 13))
		i++;
	if (*(nptr + i) == '-' || (*(nptr + i) == '+'))
	{
		if (*(nptr + i) == '-')
			neg++;
		i++;
	}
	while ((*(nptr + i) >= '0') && (*(nptr + i) <= '9'))
	{
		result *= 10;
		result += (*(nptr + i) - 48);
		i++;
	}
	neg = neg % 2;
	if (neg == 1)
		result = -result;
	return (result);
}
/*int	main()
{
	char * test = " -  ";
	printf("%d\n", atoi(test));
	printf("%d\n", ft_atoi(test));
	return 0;
}*/
