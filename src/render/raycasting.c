#include "../cub3d.h"

// Calculate length of ray from one x or y-side to next x or y-side
static double	calculate_delta(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	else
		return (fabs(1 / ray_dir));
}

// Calculate step and initial sideDist
static void	calculate_side_distance(t_view *v, int *step_x, int *step_y)
{
	if (v->ray_dir_x < 0)
	{
		*step_x = -1;
		v->side_dist_x = (v->x - v->map_x) * v->delta_dist_x;
	}
	else
	{
		*step_x = 1;
		v->side_dist_x = (v->map_x + 1.0 - v->x) * v->delta_dist_x;
	}
	if (v->ray_dir_y < 0)
	{
		*step_y = -1;
		v->side_dist_y = (v->y - v->map_y) * v->delta_dist_y;
	}
	else
	{
		*step_y = 1;
		v->side_dist_y = (v->map_y + 1.0 - v->y) * v->delta_dist_y;
	}
}
// Perform DDA alghortim far calculating pixel positions
static void	perform_dda(t_cub3d *cub3d, int step_x, int step_y)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub3d->v.side_dist_x < cub3d->v.side_dist_y)
		{
			cub3d->v.side_dist_x += cub3d->v.delta_dist_x;
			cub3d->v.map_x += step_x;
			cub3d->v.side = 0;
		}
		else
		{
			cub3d->v.side_dist_y += cub3d->v.delta_dist_y;
			cub3d->v.map_x += step_y;
			cub3d->v.side = 1;
		}
		if (cub3d->map.map[(int)cub3d->v.map_x][(int)cub3d->v.map_y] == '1')
			hit = 1;
	}
}

void set_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	int pixel = (y * cub3d->game.img.line_length) + (x * (cub3d->game.img.bpp / 8));
	*(int *)(cub3d->game.img.img + pixel) = color;
}

void draw_vertical_line(t_cub3d *cub3d, int x, int start, int end, int color)
{
	int		y;
	char	*pixel_addr;

	y = start;
	while (y <= end)
	{
		pixel_addr = cub3d->game.img.addr + ((y) * cub3d->game.img.line_length + (x) * (cub3d->game.img.bpp / 8));
		if (pixel_addr < cub3d->game.img.addr + cub3d->game.img.line_length * HEIGHT)
			*(unsigned int *)pixel_addr = color;
		y++;
	}
}

void	raycasting(t_cub3d *cub3d)
{
	int	x;
	int	step_x;
	int	step_y;
	
	x = 0;
	step_x = 0;
	step_y = 0;
	while (x < WIDTH)
	{
		cub3d->v.camera_x = 2 * x / (double) WIDTH - 1;
		cub3d->v.ray_dir_x = cub3d->v.dir_x + cub3d->v.plane_x * cub3d->v.camera_x;
		cub3d->v.ray_dir_y = cub3d->v.dir_y + cub3d->v.plane_y * cub3d->v.camera_x;
		cub3d->v.map_x = (int)cub3d->v.x;
		cub3d->v.map_y = (int)cub3d->v.y;
		cub3d->v.delta_dist_x = calculate_delta(cub3d->v.ray_dir_x);
		cub3d->v.delta_dist_y = calculate_delta(cub3d->v.ray_dir_y);
		calculate_side_distance(&cub3d->v, &step_x, &step_y);
		perform_dda(cub3d, step_x, step_y);
		if (cub3d->v.side == 0)
			cub3d->v.distance = (cub3d->v.side_dist_x - cub3d->v.delta_dist_x);
		else
			cub3d->v.distance = (cub3d->v.side_dist_y - cub3d->v.delta_dist_y);
		cub3d->v.line_height = (int)(HEIGHT / cub3d->v.distance);
		cub3d->v.draw_start = ((-cub3d->v.line_height) / 2) + (HEIGHT / 2);
		if (cub3d->v.draw_start < 0)
			cub3d->v.draw_start = 0;
		cub3d->v.draw_end = (cub3d->v.line_height / 2) + (HEIGHT / 2);
		if (cub3d->v.draw_end >= HEIGHT)
			cub3d->v.draw_end = HEIGHT - 1;
		draw_vertical_line(cub3d, x, cub3d->v.draw_start, cub3d->v.draw_end, 0xFF0000);
		x++;
	}
}
/*
if (cub3d->v.ray_dir_x == 0)
	cub3d->v.delta_dist_x = 1e30;
else
	cub3d->v.delta_dist_x = fabs(1 / cub3d->v.ray_dir_x);
if (cub3d->v.ray_dir_y == 0)
	cub3d->v.delta_dist_y = 1e30;
else
	cub3d->v.delta_dist_y = fabs(1 / cub3d->v.ray_dir_y);
if (cub3d->v.ray_dir_x < 0)
{
	step_x = -1;
	cub3d->v.side_dist_x = (cub3d->v.x - cub3d->v.map_x) * cub3d->v.delta_dist_x;
}
else
{
	step_x = 1;
	cub3d->v.side_dist_x = (cub3d->v.map_x + 1.0 - cub3d->v.x) * cub3d->v.delta_dist_x;
}
if (cub3d->v.ray_dir_y < 0)
{
	step_y = -1;
	cub3d->v.side_dist_y = (cub3d->v.y - cub3d->v.map_y) * cub3d->v.delta_dist_y;
}
else
{
	step_y = 1;
	cub3d->v.side_dist_y = (cub3d->v.map_y + 1.0 - cub3d->v.y) * cub3d->v.delta_dist_y;
}
int		hit = 0;
while (hit == 0)
{
if (cub3d->v.side_dist_x < cub3d->v.side_dist_y)
{
cub3d->v.side_dist_x += cub3d->v.delta_dist_x;
cub3d->v.map_x += step_x;
cub3d->v.side = 0;
}
else
{
cub3d->v.side_dist_y += cub3d->v.delta_dist_y;
cub3d->v.map_y += step_y;
cub3d->v.side = 1;
}
if (cub3d->map.map[(int)cub3d->v.map_x][(int)cub3d->v.map_y] != '0')
hit = 1;
}
*/