/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:08:33 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/09 07:28:10 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*int main()
{
        char c;
        c = 'z';
        if (ft_isdigit(c))
                printf("%c is digit\n", c);
        else
                printf("%c is not digit\n", c);
        c = 'A';
        if(ft_isdigit(c))
                printf("%c is digit\n", c);
        else
                printf("%c is not digit\n", c);
        c = '1';
        if (ft_isdigit(c))
                printf("%c is digit\n", c);
        else
                printf("%c is not digit\n", c);
        c = '%';
        if (ft_isdigit(c))
                printf("%c is digit\n", c);
        else
                printf("%c is not digit\n", c);

        return (0);
}*/
