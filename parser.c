# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE_s 1

typedef struct s_map
{
	int **dots;

	int weidth;
	int height;
}				t_map;

int		ft_wordscounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

void size_of_map(t_map *db, char *filename)
{
	int fd;
	fd = 0;
	char *line;

	fd = open(filename, O_RDONLY, 0);
	get_next_line(fd, &line);
	db->weidth = ft_wordscounter(line, ' ');
	free(line);
	while(get_next_line(fd, &line))
	{
		db->height++;
		free(line);
	}
	close(fd);
}


/*
static int		get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE_s + 1];
	char			*p_n;
	char			*tmp;
	int				rd;

	p_n = NULL;
	rd = 1;
	*line = checkrest(&p_n, rest);
	while (p_n == 0 && ((rd = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[rd] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}

*/

void parse(char *filename, t_map *db)
{
	int fd;
	int rd;
	rd = 0;
	char buf[2];
	buf [1] = 0;

	char c;
	c = 0;
	int i;
	i = 0;
	int y_cnt;
	y_cnt = 0;
	int x_cnt;
	x_cnt = 0;
	int z_cnt;
	z_cnt = 0;

	fd = open(filename, O_RDONLY, 0);
	db->dots = (int **)malloc(sizeof(int *) * (db->height * db->weidth));
	while((rd = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (buf[0] == '\n')
		{
			y_cnt++;
		}
		else
		{
			db->dots[i] = (int *)ft_memalloc(sizeof(int) * 4);
			db->dots[i][0] = x_cnt;
			db->dots[i][1] = y_cnt;
			db->dots[i][2] = buf[0];
			x_cnt++;
			i++;
		}
	}
	close(fd);
}





int main(int argc, char **argv)
{
	t_map *d = (t_map *)malloc(sizeof(t_map));

	parse(argv[1], d);

	int i = 0;
	while(i < d->weidth)
	{
		printf("%i %i %i \n", d->dots[i][0], d->dots[i][1], d->dots[i][2]);
		i++;
	}

}
