/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <alimotta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:34:30 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/15 16:40:05 by alimotta         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"

typedef enum e_orientation
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}		t_orientation;

typedef enum e_object
{
	EMPTY,
	WALL,
	COIN,
	DOOR
}		t_object;

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

typedef struct s_check
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	map;
}		t_check;

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
	int			x;
	int			y;
	int			p_x;
	int			p_y;
	float		distance_to_plane;
	float		angle;
	float		fov_rd;
	int			rot;
	int			l_r;
	int			u_d;
}		t_player;

typedef struct s_ray
{
	float		ray_ngl;
	float		distance;
	float		distance_scale;
	float		wall_w;
	int			flag;
	char		type;
	int			index;
}		t_ray;

typedef struct s_intersect
{
	float		inter;
	float		offset;
	char		type;
	int			index;
}		t_intersect;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_length;
	int			endian;
	int			counter;
	int			load;
	int			index;
}		t_texture;

typedef struct s_sprite
{
	int			x;
	int			y;
	float		p_x;
	float		p_y;
	float		d_x;
	float		d_y;
	float		delta_x;
	float		delta_y;
	float		distance;
	float		distance_to_plane;
	int			sprite_h;
	int			sprite_w;
	int			t_pixel;
	int			b_pixel;
	int			l_pixel;
	int			r_pixel;
	int			sprite_screen_x;
	bool		is_visible;
	t_texture	*textures;
}		t_sprite;

typedef struct s_door
{
	int			index;
	char		type;
	int			x;
	int			y;
	float		p_x;
	float		p_y;
	float		d_x;
	float		d_y;
	int			t_pixel;
	int			b_pixel;
	float		distance_to_player;
	t_texture	texture;
}		t_door;

typedef struct s_cub3d
{
	t_mlx		game;
	t_map		map;
	t_player	p;
	t_ray		ray;
	t_texture	textures[4];
	t_texture	bonus_coins[6];
	t_texture	bonus_door[9];
	int			num_coins;
	int			num_doors;
	t_door		*doors;
	t_sprite	*coins;	
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
int				check_middle(char *line);
int				check_line_edge(char *line);
//PARSING/parsing_colour.c
int				is_rgb(char *line);
int				is_fc(char *line, t_check *check);
void			rgb_to_hex(char *line, unsigned int *colour);
void			set_fc(t_map *map, char *line);
//PARSING/parsing_texture.c
int				check_texture(char *texture);
int				is_texture(char *line, t_check *check);
void			set_texture(t_map *map, char *texture);
void			free_t_map(t_map *map);
//PARSING
int				is_empty(char *line);
int				is_map(char *line);
void			preparse_check(char *str);
int				check_extension(char *filename);

//INITIATE FOLDER
void			map_init(t_map *map);
t_mlx			initiate_mlx(void);
t_player		initiate_player(t_map map);
t_ray			initiate_ray(t_player p);
void			load_all_texture(t_cub3d *cub3d);
void			initiate_sprite(t_cub3d *cub3d, int i, int x, int y);
void			update_counter(t_cub3d *cub3d, int *i, int *dir);
void			initiate_doors(t_cub3d *cub3d, int i, int x, int y);

//INPUT FOLDER
int				x_pressed(t_cub3d *cub3d);
int				key_press(int ks, t_cub3d *cub3d);
int				key_release(int ks, t_cub3d *cub3d);
void			check_for_input(t_cub3d *cub3d, float move_x, float move_y);
void			rotate_player(t_cub3d *cub3d, int i);
int 			handle_mouse(int button, int x, int y, t_cub3d *cub3d);
int 			mouse_press(int button, int x, int y, t_cub3d *cub3d);
int				mouse_release(int button, int x, int y, t_cub3d *cub3d);

//RENDER FOLDER
void			clear_mini_map(t_mlx *game);
int				render_mini_map(t_cub3d *cub3d);
void			draw_square_minimap(t_mlx *game, int w, int h, int color);
void			raycasting(t_cub3d *cub3d);
void			render_enviroment(t_cub3d *cub3d, int ray);
void			draw_pixel(t_cub3d *cub3d, int ray, unsigned int color, int i);
void			draw_sprite(t_cub3d *cub3d, t_sprite *sprite, int texture_x,
					int texture_y);
void			render_sprite(t_cub3d *cub3d, int i, int dir);
bool			is_sprite_visible(t_cub3d *cub3d, t_sprite *sprite,
					int map_x, int map_y);
void			check_doors(t_cub3d *cub3d, int i, int index);
void			raycasting_door(t_cub3d *cub3d, int ray);
void			render_door(t_cub3d *cub3d, int ray);
int				find_index_door(t_cub3d *cub3d, int pos_y, int pos_x);
float			nor_angle(float angle);
int				unit_circle(float angl, char c);
int				intersection_check(float angl, float *inter,
					float *step, int is_horizon);
void			set_right_intersection(t_cub3d *cub3d,
					t_intersect inter, int flag);
unsigned int	get_tex_color(t_texture texture, int x, int y);

//CLEAN FOLDER
int				ft_error(int argc, char **argv);
void			ft_destroy_mlx(t_cub3d *cub3d);
void			initiate_error_win(t_mlx game);
void			initiate_error_img_minimap(t_mlx game);
void			initiate_error_img_map(t_mlx game);
void			initiate_error_texture(t_mlx *game, t_texture *texture, int i);
void			free_double_array(char **array);
void			free_double_array(char **array);
int				parsing_error(char *message);

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
# ifndef DISTANCE_WALL
#  define DISTANCE_WALL 5
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
#  define FRAME_SPRITE 6
# endif
# ifndef FRAME_DOOR
#  define FRAME_DOOR 9
# endif
#endif