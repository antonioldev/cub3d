/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:25:25 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:27:13 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = '\0';
		i++;
	}
}
/*int	main()
{
	char test[50] = "Ciao mi chiamo antonio";
	char my_test2[50] = "Ciao mi chiamo antonio";
	int test3[50] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int my_test4[50] = {1,2,3,4,5,6,7,8,9,10,11,12};
	bzero(test, 12);
	ft_bzero(my_test2,12);
	bzero(test3, 5);
	ft_bzero(my_test4, 5);
	int i;

	for (i = 0; i < 50; i++)
        printf("%d ", my_test4[i]);
        printf("\nSTRING: %s\n", my_test2);

	printf("ORIGINAL\n");

	for (i = 0; i < 50; i++)
	printf("%d ", test3[i]);
	printf("\nSTRING: %s\n", test);

	return (0);
}*/
