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

    x_step = x1 - x;
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
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "ROTATION:");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "X, Y rotation - LMB & drag");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Z rotation - \"Z\" & \"X\"");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Movement in front plane - RMB & drag");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Slow zoom - Scroll mouse wheel");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "Fast zoom - MMB & drag");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 30, color, "RENDER:");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "1 - Vertex");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "2 - Wireframe");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "3 - Silhouette");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "4 - Hard mesh");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 30, color, "P - Projection");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "R - Reset transform");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 20, color, "F - Focus in center");
    mlx_string_put(d->mlx_ptr, d->win_ptr, start_x, y += 50, color, "ESC - Exit from FDF");
        
}

void print_left_block(t_map *d, int size_x, int size_y, int color)
{
    int x_start;
    int y_start;
    int x_end;
    int y_end;

    x_start = 20;
    y_start = 20;
    x_end = x_start + size_x;
    y_end = y_start + size_y;
    draw_line((int)x_start, (int)y_start, (int)x_end, (int)y_start, d);
    draw_line((int)x_start, (int)y_start, (int)x_start, (int)y_end, d);
    draw_line((int)x_end, (int)y_start, (int)x_end, (int)y_end, d);
    draw_line((int)x_start, (int)y_end, (int)x_end, (int)y_end, d);

}