/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:34:30 by alimotta          #+#    #+#             */
/*   Updated: 2024/06/04 16:58:05 by rtavabil         ###   ########.fr       */
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
# include "../libs/libft/libft.h"

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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_n;
	void	*img_s;
	void	*img_w;
	void	*img_e;
	int		width;
	int		height;
	int		height_minimap;
	int		size_minimap;	
}		t_mlx;

typedef struct s_cub3d
{
	t_mlx	game;
	t_map	map;
}		t_cub3d;

//PARSING FOLDER
char		*ft_read_from_file(int fd, char *s);
int			ft_error(int argc, char **argv);
char		*ft_read_from_file(int fd, char *s);
int			check_borders(char	**map);
int			count_lines(char **map);
char		**format_map(char **map, int w);
int			count_colum(char **map);
int			check_zero(char **map, int w, int h);
int			check_player(char **map);
int			is_allowed_p(char c);
int			is_allowed_all(char c);
void		set_player_pos(t_map **map);
void		create_map(t_map *map, int fd);

//PARSING/parsing_colour.c
int			is_rgb(char *line);
int			is_fc(char *line);
void		rgb_to_hex(char *line, unsigned int *colour);
void		set_fc(t_map *map, char *line);
//PARSING/parsing_texture.c
int			check_texture(char *texture);
int			is_texture(char *line);
void		set_texture(t_map *map, char *texture);
////////////////////////////
void		free_t_map(t_map *map);




//INITIATE FOLDER
void		map_init(t_map *map);
t_mlx		initiate_mlx(t_map *map);

//INPUT FOLDER
int			x_pressed(t_cub3d *cub3d);
int			handle_input(int ks, t_cub3d *cub3d);
void		ft_move_left(t_map *map);
void		ft_move_right(t_map *map);
void		ft_move_up(t_map *map);
void		ft_move_down(t_map *map);

//RENDER FOLDER
int			render_mini_map(t_cub3d *cub3d);
void		clear_mini_map(t_cub3d *cub3d);

//CLEAN FOLDER
int			ft_error(int argc, char **argv);
void		ft_destroy_mlx(t_mlx *game);
void		free_double_array(char **array);
int			parsing_error(char *message);

#endif