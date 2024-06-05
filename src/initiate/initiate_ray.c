/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:22:14 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/05 14:17:28 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Initiate the ray struct and set all variables to zero*/
t_ray	initiate_ray(t_player p)
{
	t_ray	ray;

	ray.distance = 0;
	ray.flag = 0;
	ray.ray_ngl = 0;
	ray.distance_scale = TILE_SIZE * p.distance_to_plane;
	return (ray);
}
