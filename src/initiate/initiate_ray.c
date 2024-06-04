/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:22:14 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/04 17:40:02 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Initiate the ray struct and set all variables to zero*/
t_ray	initiate_ray(void)
{
	t_ray	ray;

	ray.distance = 0;
	ray.flag = 0;
	ray.ray_ngl = 0;
	// ray.wall_x = 0;
	return (ray);
}
