/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:50:43 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/04 19:25:40 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*For each ray calculate the vertical and horizontal intersection*/
void	raycasting(t_cub3d *cub3d)
{
	double	h_inter;
	double	v_inter;
	int		ray;
	float	wall_x;

	ray = 0;
	cub3d->ray.ray_ngl = cub3d->p.angle - (cub3d->p.fov_rd / 2);
	while (ray < WIDTH)
	{
		cub3d->ray.flag = 0;
		h_inter = find_h_inter(cub3d, cub3d->ray.ray_ngl);
		v_inter = find_v_inter(cub3d, cub3d->ray.ray_ngl);
		if (v_inter <= h_inter)
		{
			cub3d->ray.distance = v_inter;
			cub3d->ray.flag = 0;
		}
		else
		{
			cub3d->ray.distance = h_inter;
			cub3d->ray.flag = 1;
		}
		cub3d->ray.distance *= cos(nor_angle(cub3d->ray.ray_ngl - \
					cub3d->p.angle));
		render_wall(cub3d, ray);
		ray++;
		cub3d->ray.ray_ngl += (cub3d->p.fov_rd / WIDTH);
	}
}

/*It keep rendering the map and minimap on display*/
int	refresh_win(t_cub3d *cub3d)
{
	check_for_input(cub3d, 0, 0);
	clear_mini_map(&cub3d->game);
	render_mini_map(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win,
		cub3d->game.img.img, 0, 0);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win,
		cub3d->game.img_minimap.img, 0, HEIGHT);
	return (0);
}
