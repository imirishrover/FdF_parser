#include "nsance.h"

#define MAX_NSANCE(a, b) (a > b ? a : b)

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void draw_line(float x, float y, float x1, float y1, t_map *db)
{
    float x_step;
    float y_step;
    int max;

    x_step = x1 - y;
    y_step = y1 - y;

    max = MAX_NSANCE(fmodule(x_step), fmodule(y_step));
    x_step /= max;
    y_step /= max;
    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(db->mlx_ptr, db->win_ptr, x, y, 0xffffff);
        x += x_step;
        y += y_step;
    }
}


void draw_all(t_map *d)
{
    int x;
    int y;
    int j;
    int max_s = d->height * d->width;

    y = 0;
    j = 0;
    while(y < d->height)
    {
        x = 0;
        while(x < d->width)
        {
            if (j < max_s)
                draw_line(d->dots[j][0], d->dots[j][1], d->dots[j + 1][0], d->dots[j][1], d);
            //draw_line(d->dots[j][0], d->dots[j][1], d->dots[j][0], d->dots[j + 1][1], d);
            x++;
            j++;
        }
        y++;
    }
}


void print_manual(t_map *d, int start_x, int start_y, int color)
{
    int y;
    y = start_y;
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "How to Use");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Press key to do smth");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Press key to do smth");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Press key to do smth");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Press key to do smth");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Press key to do smth");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Press key to do smth");
    mlx_
}