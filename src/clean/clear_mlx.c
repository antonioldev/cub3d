/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:35 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/06 07:48:00 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Free memory allocated for the map*/
void	free_t_map(t_map *map)
{
	if (map->no != NULL)
		free(map->no);
	if (map->so != NULL)
		free(map->so);
	if (map->we != NULL)
		free(map->we);
	if (map->ea != NULL)
		free(map->ea);
	if (map->map != NULL)
		free_double_array(map->map);
}

/*Destroy the mlx window and mlx display and free memory*/
void	ft_destroy_mlx(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(cub3d->game.mlx, cub3d->textures[i].img);
	i = -1;
	while (++i < FRAME_SPRITE)
		mlx_destroy_image(cub3d->game.mlx, cub3d->bonus_texture[i].img);
	mlx_destroy_image(cub3d->game.mlx, cub3d->game.img_minimap.img);
	mlx_destroy_image(cub3d->game.mlx, cub3d->game.img.img);
	mlx_destroy_window(cub3d->game.mlx, cub3d->game.win);
	mlx_destroy_display(cub3d->game.mlx);
	free (cub3d->game.mlx);
	free_t_map(&cub3d->map);
}
