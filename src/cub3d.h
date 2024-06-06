/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:34:30 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/06 07:18:34 by alimotta         ###   ########.fr       */
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

typedef enum e_orientation
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}		t_orientation;

typedef struct s_map
{
	//should contain path to texture that should be set on a given direction
	//will be set to NULL in case nothing was given
	char			*no;
	char			*so;
	char			*we;
	char			*ea;

	//each number will be set to -1 in case nothing was given
	unsigned int	f;
	unsigned int	c;
	int				x;
	int				y;
	int				width;
	int				height;
	//char table containing map
	char			**map;
	char			player_orientation;
}		t_map;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}		t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		img_minimap;
}		t_mlx;

typedef struct s_player
{
	int			p_x;
	int			p_y;
	float		distance_to_plane;
	double		angle;
	float		fov_rd;
	int			rot;
	int			l_r;
	int			u_d;
}		t_player;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_length;
	int			endian;
}		t_texture;

typedef struct s_ray
{
	double		ray_ngl;
	double		distance;
	double		distance_scale;
	double		wall_x;
	int			flag;
}		t_ray;

typedef struct s_intersect
{
	double	inter;
	double	offset;
}		t_intersect;

typedef struct s_cub3d
{
	t_mlx		game;
	t_map		map;
	t_player	p;
	t_ray		ray;
	t_texture	textures[4];
	t_texture	bonus_texture[8];
}		t_cub3d;

//PARSING FOLDER
char			*ft_read_from_file(int fd, char *s);
int				ft_error(int argc, char **argv);
char			*ft_read_from_file(int fd, char *s);
int				check_borders(char	**map);
int				count_lines(char **map);
char			**format_map(char **map, int w);
int				count_colum(char **map);
int				check_zero(char **map, int w, int h);
int				check_player(char **map);
int				is_allowed_p(char c);
int				is_allowed_all(char c);
void			set_player_pos(t_map **map);
void			create_map(t_map *map, int fd);

//PARSING/parsing_colour.c
int				is_rgb(char *line);
int				is_fc(char *line);
void			rgb_to_hex(char *line, unsigned int *colour);
void			set_fc(t_map *map, char *line);
//PARSING/parsing_texture.c
int				check_texture(char *texture);
int				is_texture(char *line);
void			set_texture(t_map *map, char *texture);
void			free_t_map(t_map *map);



//INITIATE FOLDER
void			map_init(t_map *map);
t_mlx			initiate_mlx(void);
t_player		initiate_player(t_map map);
t_ray			initiate_ray(t_player p);
void			load_all_texture(t_cub3d *cub3d);


//INPUT FOLDER
int				x_pressed(t_cub3d *cub3d);
int				key_press(int ks, t_cub3d *cub3d);
int				key_release(int ks, t_cub3d *cub3d);
void			check_for_input(t_cub3d *cub3d, double move_x, double move_y);

//RENDER FOLDER
int				refresh_win(t_cub3d *cub3d);
void			clear_mini_map(t_mlx *game);
int				render_mini_map(t_cub3d *cub3d);
void			draw_square_minimap(t_mlx *game, int w, int h, int color);
void			find_h_inter(t_cub3d *cub3d, float angl, \
					t_intersect *intersect);
void			find_v_inter(t_cub3d *cub3d, float angl, \
					t_intersect *intersect);
void			render_wall(t_cub3d *cub3d, int ray);
float			nor_angle(float angle);
unsigned int	get_texture_color(t_texture texture, int x, int y);
t_texture		get_texture(t_cub3d *cub3d, int flag);
void			draw_pixel(t_cub3d *cub3d, int ray, int color, int i);

//CLEAN FOLDER
int				ft_error(int argc, char **argv);
void			ft_destroy_mlx(t_cub3d *cub3d);
void			initiate_error_win(t_mlx game);
void			initiate_error_img_minimap(t_mlx game);
void			initiate_error_img_map(t_mlx game);
void			initiate_error_texture(t_mlx *game, t_texture *texture, int i);
void			free_double_array(char **array);
void		free_double_array(char **array);
int			parsing_error(char *message);

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 600
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
# ifndef FOV
#  define FOV 60
# endif
# ifndef ROTATION_SPEED
#  define ROTATION_SPEED 0.005
# endif
# ifndef PLAYER_SPEED
#  define PLAYER_SPEED 1
# endif
# ifndef PLAYER_HEIGHT
#  define PLAYER_HEIGHT 32
# endif
# ifndef FRAME_SPRITE
#  define FRAME_SPRITE 8
# endif
#endif