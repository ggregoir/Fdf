/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:45:34 by ggregoir          #+#    #+#             */
/*   Updated: 2017/02/01 18:15:57 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		getnb(char *str)
{
	int nb;
	int neg;

	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		str++;
	}
	nb = 0;
	while ((*str >= '0') && (*str <= '9'))
		nb = (nb * 10) + *str++ - '0';
	return ((neg == 1) ? -nb : nb);

}

int		ft_pts(char *line, int nb_lines, point_t ***points)
{
	char **array_str;
	point_t *pt;
	int i;

	array_str = ft_strsplit(line, ' ');
	i = 0;
	while (array_str[i] != 0)
		i++;
	if (!((*points) = (point_t**)malloc(sizeof(point_t) * i)))
		malloc_error();
	i = 0;
	while (array_str[i] != 0)
	{
		if (!(pt = (point_t*)malloc(sizeof(point_t))))
			malloc_error();
		pt->x = i * SIZE_W;
		pt->y = nb_lines * SIZE_H;
		pt->h = getnb(array_str[i]);
		pt->h_color = pt->h;
		(*points)[i] = pt;
		i++;
	}
	return (i);
}

int		ft_nb_lines(char *line)
{
	int 	fd;
	int 	nb_lines;
	char	buf;

	fd = 0;
	nb_lines = 0;
	if ((fd = open(line, O_RDONLY)) < 0)
		map_error();
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nb_lines++;
	}
	close(fd);
	return(nb_lines);
}



map_t	*read_map(char ** argv, int fd)
{
	int		nb_lines;
	char	*line;
	point_t **points;
	lines_t *lines;
	map_t	*map;

	nb_lines = 0;
	if (!(map = (map_t*)malloc(sizeof(map_t))) ||
	!(map->lines = (lines_t**)malloc(sizeof(lines_t)* ft_nb_lines(argv[1]))))
		malloc_error();
	map->len = 0;
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(lines = (lines_t*)malloc(sizeof(lines_t))))
				malloc_error();
			lines->len = ft_pts(line, nb_lines, &points);
			lines->points = points;
			map->lines[nb_lines] = lines;
			nb_lines++;
		}
		map->len = nb_lines;
	}
	return(map);
}