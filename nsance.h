#ifndef NSANCE_H
#define NSANCE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"
# include <stdio.h>
# include "minilibx_macos/mlx.h"

# define DIVIDE_SYMBOL ' '
# define AMOUNT_OF_PARAMETERS_PER_DOT 3
# define TEXT_COLOR 0xffffff

typedef struct s_map
{
	int **dots;

	int width;
	int height;

    void		*mlx_ptr;
	void		*win_ptr;
}			    t_map;

int		ft_wordscounter(char const *str, char c);
void fill_matrix(t_map *db, char **line_of_z, int i_starts_from, int y);
int allocate_mem(char *filename, t_map *d);
int parse(char *filename, t_map *d);

void draw_line(float x, float y, float x1, float y1, t_map *db);
void draw_all(t_map *d);
void print_manual(t_map *d, int start_x, int start_y, int color);

#endif