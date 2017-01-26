/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:45:34 by ggregoir          #+#    #+#             */
/*   Updated: 2017/01/23 19:22:16 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../includes/fdf.h"

int		verif_count(char *line, verif_t *v)
{
	while (v->y != v->my)
	{
		printf("boucle y\n");
		while (map[v->y][v->x])
		{
			printf("boucle x\n");
			if(map[v->y][v->x] < '0' || map[v->y][v->x] > '9')
				return (0);
			v->x++;
		}
		if (ft_strlen(map[v->y]) - 1 != (unsigned long)v->mx)
			return (0);
		v->y++;
	}
	return(1);
}

char	**read_map(char ** argv)
{
	int		fd;
	char	*line;
	char	**map;
	verif_t v;

	fd = 0;
	map = NULL;
	if ((fd = open(argv[1], O_RDONLY)) < 1)
	{
		ft_putstr("open() error");
		return (0);
	}
	printf("lul\n");
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		*map[v.y] = *line;
		printf("test\n");
		v.y++;
	}
	v.mx = ft_strlen(line) - 1;
	v.my = v.y;
	v.y = 0;
	if (verif_count(map, &v) == 1)
		return(map);
	return (0);
}