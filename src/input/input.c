/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:18:53 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/22 16:19:09 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Exit the loop when pressing X button*/
int	x_pressed(t_mlx *game)
{
	mlx_loop_end (game->mlx);
	return (0);
}