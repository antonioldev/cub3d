/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:17:30 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:27:59 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*int main()
{
	char c;
	c = 'z';
	if (ft_isascii(c))
		printf("%c is ascii\n", c);
	else
		printf("%c is not ascii\n", c);
	c = 'A';
        if(ft_isascii(c))
                printf("%c is ascii\n", c);
        else
                printf("%c is not ascii\n", c);
	c = '1';
        if (ft_isascii(c))
                printf("%c is ascii\n", c);
        else
                printf("%c is not ascii\n", c);
	c = '%';
        if (ft_isascii(c))
                printf("%c is ascii\n", c);
        else
                printf("%c is ascii\n", c);

	return (0);
}*/
