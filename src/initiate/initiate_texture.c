/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:43:21 by antonio           #+#    #+#             */
/*   Updated: 2024/06/08 13:11:31 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_texture(t_texture *texture, t_mlx *game, char *filename, int i)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, filename, \
			&texture->width, &texture->height);
	if (texture->img == NULL)
		initiate_error_texture(game, texture, i);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
			&texture->line_length, &texture->endian);
}

static char	int_to_char(int i)
{
	if (i >= 0 && i <= 9)
		return (i + '0');
	return ('\0');
}

void	load_all_texture(t_cub3d *cub3d)
{
	int		i;
	char	*path;

	load_texture(&cub3d->textures[NORTH], &cub3d->game, "./texture/wall_N.xpm", NORTH);
	load_texture(&cub3d->textures[SOUTH], &cub3d->game, "./texture/wall_S.xpm", SOUTH);
	load_texture(&cub3d->textures[WEST], &cub3d->game, "./texture/wall_W.xpm", WEST);
	load_texture(&cub3d->textures[EAST], &cub3d->game, "./texture/wall_E.xpm", EAST);
	i = 0;
	path = ft_strdup("./texture/bonus/frame_0.xpm");
	while (i < FRAME_SPRITE)
	{
		path[22] = int_to_char(i);
		load_texture(&cub3d->bonus_texture[i], &cub3d->game, path, i);
		i++;
	}
	free (path);
	cub3d->bonus_texture->counter = 0;
	cub3d->bonus_texture->load = 0;
}
