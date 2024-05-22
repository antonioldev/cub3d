/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:58:52 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/22 17:01:49 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



void	render_map(t_mlx *game, t_map *map)
{
	int	w_map;
	int	h_map;
	int	w;
	int	h;

	h = 0;
	h_map = 0;
	while (v -> height > 0)
	{
		w = 0;
		w_map = 0;
		while (w_map < v -> width)
		{
			put_image_to_map(v -> arr[h_map][w_map], w, h, &v);
			w_map++;
			w += v->s;
		}
		h_map++;
		h += v->s;
		v -> height--;
	}
}