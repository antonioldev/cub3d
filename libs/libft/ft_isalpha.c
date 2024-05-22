/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:55:04 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:27:46 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
/*int	main()
{
	char c;
	c = 'z';
	if (ft_isalpha(c))
		printf("%c is alphabetic\n", c);
	else
		printf("%c is NOT alphabetic\n", c);
	c = 'A';
	if (ft_isalpha(c))
		printf("%c is alphabetic\n", c);
	else
		printf("%c is NOT alphabetic\n", c);
	c = '1';
	if (ft_isalpha(c))
		printf("%c is alphabetic\n", c);
	else
		printf("%c is NOT alphabetic\n", c);
	c = '%';
	if (ft_isalpha(c))
		printf("%c is alphabetic\n", c);
	else
		printf("%c is NOT alphabetic\n", c);
	c = '\t';
	if (ft_isalpha(c))
		printf("%c is alphabetic\n", c);
	else
		printf("%c is NOT alphabetic\n", c);
	return(0);
}*/
