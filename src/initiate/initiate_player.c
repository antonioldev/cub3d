/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:21:29 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/28 17:20:55 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player	initiate_player(void)
{
	t_player	player;

	player.pl_speed = 3;
	player.rot = 0;
	player.rot_speed = 0.020;
	return (player);
}
