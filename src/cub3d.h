/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:34:30 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/22 17:03:21 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <X11/keysym.h>

typedef struct	s_map
{
	//should contain path to texture that should be set on a given direction
	//will be set to NULL in case nothing was given
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	//each number will be set to -1 in case nothing was given
	int		f[3];
	int		c[3];

	//char table containing map
	char	**map;
}		t_map;


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_n;
	void	*img_s;
	void	*img_w;
	void	*img_e;
	
}		t_mlx;



//INITIATE FOLDER
void		initiate_mlx(t_mlx *game, t_map *map);

//INPUT FOLDER
int			x_pressed(t_mlx *game);

//CLEAN FOLDER
void		ft_destroy_mlx(t_mlx *game);
#endif