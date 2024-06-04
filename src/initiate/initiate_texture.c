/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:43:21 by antonio           #+#    #+#             */
/*   Updated: 2024/06/04 19:10:00 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void load_texture(t_texture *texture, t_mlx *game, char *filename, int i)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, filename, &texture->width, &texture->height);
	if (texture->img == NULL)
		initiate_error_texture(game, texture, i);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_length, &texture->endian);
}