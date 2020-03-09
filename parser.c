
#include "nsance.h"

/*
** Count words in the string divided by 'c'
*/
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

/*
**Writes a line from the file in the array of ints
*/
void fill_matrix(t_map *db, char **line_of_z, int i_starts_from, int y)
{
	int k = i_starts_from;
	while(k < (i_starts_from + db->width))
	{
		if (!(db->dots[k] = (int *)malloc(sizeof(int) * AMOUNT_OF_PARAMETERS_PER_DOT)))
			{
				write(1, "malloc error\n", 13);
				return;
			}
		else
			{
				db->dots[k][0] = (k - i_starts_from);
				db->dots[k][1] = y;
				db->dots[k][2] = ft_atoi(line_of_z[k - i_starts_from]);
				free(line_of_z[k - i_starts_from]);
				k++;
			}
	}
}

int allocate_mem(char *filename, t_map *d)
{
	int height;
	int width;
	int **n = 0;

	int fd;
	fd = 0;
	char *line = 0;

	if ((fd = open(filename, O_RDONLY, 0)) <= 0)
	{
		write(1, "file not exists", 15);
		return(0);
	}
	get_next_line(fd, &line);
	if (line && ft_strlen(line))
		height++;
	width = ft_wordscounter(line, ' ');
	free(line);
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	d->height = height;
	d->width = width;
	d->dots = (int **)malloc(sizeof(int *) * (height * width));
	d->dots[height * width] = 0;
	return(1);
}



int parse(char *filename, t_map *d)
{
	int fd = 0;
	int cnt = 0;
	int y_cnt;
	y_cnt = 0;
	char *next_line = 0;
	char **splitted_line = 0;
	if (!allocate_mem(filename, d))
		return(0);
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		write(1, "Error opening file\n", 19);
		return(0);
	}
	while(get_next_line(fd, &next_line))
	{
		splitted_line = ft_strsplit(next_line, DIVIDE_SYMBOL);
		fill_matrix(d, splitted_line, cnt, y_cnt);
		free(next_line);
		if (splitted_line)
		{
			free(splitted_line);
		}
		cnt += d->width;
		y_cnt++;
	}
	close(fd);
	return(1);
}




