/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:31:47 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 12:16:12 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	if (nelem == 0 || elsize == 0)
	{
		ptr = malloc(0);
	}
	else if (nelem >= UINT_MAX || elsize >= UINT_MAX || nelem * elsize \
			>= UINT_MAX)
		return (NULL);
	else
	{
		ptr = malloc(nelem * elsize);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, nelem * elsize);
	}
	return (ptr);
}
/*int	main()
{
	int * ptr;
	int * ptr2;
	int i;
	int n = 5;

	ptr = (int *)ft_calloc(n, sizeof(int));
	ptr2 = (int *)calloc(n, sizeof(int));

	if (ptr == NULL)
        	printf("Memory not allocated.\n");
	else
	{
		printf("\nThe elements of the array are: ");
        	for (i = 0; i < n; ++i)
            		printf("%d, ", ptr[i]);
	}
	if (ptr2 == NULL)
                printf("Memory not allocated.\n");
	else
	{
		printf("\nThe elements of the array are: ");
        	for (i = 0; i < n; ++i)
            		printf("%d, ", ptr2[i]);
	}
	printf("\n");
	free(ptr);
	free(ptr2);
	return (0);
}*/
