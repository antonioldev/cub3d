/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:48:15 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/25 16:51:55 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_ray	initiate_ray(void)
{
	t_ray	ray;

	ray.distance = 0;
	ray.flag = 0;
	ray.ray_ngl = 0;
	return (ray);
}
