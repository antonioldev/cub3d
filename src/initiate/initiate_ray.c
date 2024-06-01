/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:22:14 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/01 08:27:53 by alimotta         ###   ########.fr       */
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
	return (ray);
}
