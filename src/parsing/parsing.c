/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:12:16 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/19 10:10:43 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//reads the whole map from the file
char	*ft_read_from_file(int fd, char *s, size_t bytes_read)
{
	char	temp[1];
	char	*s2;

	while (s == 0 || bytes_read > 0)
	{
		bytes_read = read(fd, temp, 1);
		if (s == 0 && bytes_read > 0)
		{
			s = (char *)malloc(bytes_read + 1);
			ft_strlcpy(s, temp, bytes_read + 1);
		}
		else if (bytes_read > 0)
		{
			s2 = (char *)malloc(ft_strlen(s) + bytes_read + 1);
			ft_strlcpy(s2, s, ft_strlen(s) + 1);
			ft_strlcat(s2, temp, ft_strlen(s) + bytes_read + 1);
			free (s);
			s = (char *)malloc(ft_strlen(s2) + 1);
			ft_strlcpy(s, s2, ft_strlen(s2) + 1);
			free (s2);
		}
		else if (bytes_read == 0 && s == 0)
			ft_error_empty_map();
	}
	return (s);
}
