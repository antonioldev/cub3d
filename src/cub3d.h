/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:34:30 by alimotta          #+#    #+#             */
/*   Updated: 2024/05/29 16:09:29 by alimotta         ###   ########.fr       */
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
# include <string.h>
# include <X11/keysym.h>
# include <math.h>
# include "../libs/libft/libft.h"

typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	int			x;
	int			y;
	int			width;
	int			height;
	//char table containing map
	char		**map;
	char		player_orientation;
}		t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		img_minimap;
}		t_mlx;

typedef struct s_view
{
	double		x;//position player on grid
	double		y;
	double		dir_x;//diretion player on map
	double		dir_y;
	double		plane_x;//the 2d raycaster version of camera plane
	double		plane_y;
	double		map_x;
	double		map_y;
	int			pl_speed;
	int			rot;
	int			side;
	double		rot_speed;
	double		camera_x;//coordinate on the camera plane that the current x-coordinate of the screen represents
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;// distance the ray has to travel to go from 1 x-side to the next side
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		ray_ngl;
	double		distance;
	int			flag;
	int			line_height;
	int			draw_start;
	int			draw_end;
}		t_view;

typedef struct s_cub3d
{
	t_mlx		game;
	t_map		map;
	t_view		v;
}		t_cub3d;

//PARSING FOLDER
char			*ft_read_from_file(int fd, char *s);

//INITIATE FOLDER
void			map_init(t_map *map, int fd);
t_mlx			initiate_mlx(void);
t_view			initiate_player(t_map map);

//INPUT FOLDER
int				x_pressed(t_cub3d *cub3d);
int				handle_input(int ks, t_cub3d *cub3d);
void			ft_move_left(t_map *map);
void			ft_move_right(t_map *map);
void			ft_move_up(t_map *map);
void			ft_move_down(t_map *map);

//RENDER FOLDER
int				render_mini_map(t_cub3d *cub3d);
int				render_map(t_cub3d *cub3d);
void			raycasting(t_cub3d *cub3d);
void			clear_mini_map(t_mlx *game);

//CLEAN FOLDER
int				ft_error(int argc, char **argv);
void			ft_destroy_mlx(t_mlx *game);
void			initiate_error_win(t_mlx game);
void			initiate_error_img_minimap(t_mlx game);
void			initiate_error_img_map(t_mlx game);

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 500
# endif
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif
# ifndef HEIGHT_MINI
#  define HEIGHT_MINI 100
# endif
# ifndef PIXEL_MINI
#  define PIXEL_MINI 4
# endif

#endif