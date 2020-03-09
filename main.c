#include "nsance.h"





int main(int argc, char **argv)
{
	char file[10] = "42.fdf";
	t_map *d;
	int i = 0;
    int j = 0;
    int k = 0;

	d = (t_map *)malloc(sizeof(t_map));
	if (parse("42.fdf", d))
	{
        d->mlx_ptr = mlx_init();
        d->win_ptr = mlx_new_window(d->mlx_ptr, 1920, 1080, "FDF");

        //draw_all(d);
        //draw_line(10, 10, 300, 600, d);
        print_left_block(d, 400, 600, 0xffffff);
        print_manual(d, 35, 0, 0xffffff);
        mlx_loop(d->mlx_ptr);
        while(i < d->height)
        {
            j = 0;
            while(j < d->width)
            {
                printf("%3d", d->dots[k][2]);
                k++;
                j++;
            }
            printf("\n");
            i++;
        }
	}
}
