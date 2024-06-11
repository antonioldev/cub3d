/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:50:43 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/08 15:52:06 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*Set the distance and size of walls based on the intersection*/
void	set_right_intersection(t_cub3d *cub3d, t_intersect inter, int flag)
{
	cub3d->ray.distance = inter.inter;
	cub3d->ray.wall_w = inter.offset;
	cub3d->ray.flag = flag;
}

/*For each ray calculate the vertical and horizontal intersection*/
void	raycasting(t_cub3d *cub3d, char type)
{
	t_intersect	h_inter;
	t_intersect	v_inter;
	int			ray;

	ray = 0;
	cub3d->ray.ray_ngl = cub3d->p.angle - (cub3d->p.fov_rd / 2);
	while (ray < WIDTH)
	{
		find_v_inter(cub3d, cub3d->ray.ray_ngl, &v_inter, type);
		find_h_inter(cub3d, cub3d->ray.ray_ngl, &h_inter, type);
		if (v_inter.inter <= h_inter.inter)
			set_right_intersection(cub3d, v_inter, 0);
		else
			set_right_intersection(cub3d, h_inter, 1);
		cub3d->ray.distance *= cos(nor_angle(cub3d->ray.ray_ngl - \
					cub3d->p.angle));
		render_enviroment(cub3d, ray);
		ray++;
		cub3d->ray.ray_ngl += (cub3d->p.fov_rd / WIDTH);
	}
}

/*It keep rendering the map and minimap on display*/
int	refresh_win(t_cub3d *cub3d)
{
	check_for_input(cub3d, 0, 0);
	check_doors(cub3d);
	clear_mini_map(&cub3d->game);
	render_mini_map(cub3d);
	raycasting(cub3d, '1');
	render_sprite(cub3d, 0, 0);
	render_door(cub3d, 0, 0);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win,
		cub3d->game.img.img, 0, 0);
	mlx_put_image_to_window(cub3d->game.mlx, cub3d->game.win,
		cub3d->game.img_minimap.img, 0, HEIGHT);
	return (0);
}
