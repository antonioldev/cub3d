/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:30:44 by rtavabil          #+#    #+#             */
/*   Updated: 2024/06/12 12:42:47 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//checks if line is an rgb line
//returns 1 if success, 0 otherwise
int	is_rgb(char *line)
{
	char	**rgb;
	int		num;
	int		i;
	int		ret;

	rgb = ft_split(line, ',');
	i = 0;
	ret = 1;
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			ret = 0;
		i++;
	}
	if (i != 3)
		ret = 0;
	free_double_array(rgb);
	return (ret);
}

//checking if line contains color for floor/ceiling
//returns 1 if its rgb color, 0 otherwise
int	is_fc(char *line, t_check *check)
{
	if (check != NULL)
	{
		if (!ft_strncmp(line, "F", 1))
		{
			check->f++;
			return (1);
		}
		if (!ft_strncmp(line, "C", 1))
		{
			check->c++;
			return (1);
		}
	}
	else if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (is_rgb(line + 2));
	return (0);
}

//gets hex value from rgb value and sets to according map field
void	rgb_to_hex(char *line, unsigned int *colour)
{
	unsigned int	hex;
	char			**rgb;

	rgb = ft_split(line, ',');
	hex = (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
	free_double_array(rgb);
	*colour = hex;
}

//sets floor/ceiling colour in hexadecimal
void	set_fc(t_map *map, char *line)
{
	if (!ft_strncmp(line, "F", 1))
		rgb_to_hex(line + 2, &(map->f));
	if (!ft_strncmp(line, "C", 1))
		rgb_to_hex(line + 2, &(map->c));
}
