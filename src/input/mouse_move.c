#include "../cub3d.h"

int mouse_press(int button, int x, int y, t_cub3d *cub3d)
{
    if (button == 1)
        handle_mouse(button, x, y, cub3d);
    return (x * y);
}

int mouse_release(int button, int x, int y, t_cub3d *cub3d)
{
    if (button == 1)
        cub3d->p.rot = 0;
    return (x * y);
}

int handle_mouse(int button, int x, int y, t_cub3d *cub3d)
{
	static int	old_x = WIDTH / 2;

    if (button == 1)
    {
        if (x == old_x)
            return (0);
        else if (x < old_x)
        {
            cub3d->p.rot = -1;
            rotate_player(cub3d, 1);
        }
        else if (x > old_x)
        {
            cub3d->p.rot = 1;
            rotate_player(cub3d, -1);
        }
    }
    return (x * y);
}