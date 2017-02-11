/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:16:41 by ggregoir          #+#    #+#             */
/*   Updated: 2017/02/11 12:50:20 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	center(data_t *data)
{
	point_t p;
	int 	yl;
	int 	xl;

	p = data->center;
	yl = data->map->len;
	xl = data->map->lines[yl - 1]->len;
	p.x = (data->map->lines[yl - 1]->points[xl - 1]->x + 
		data->map->lines[0]->points[0]->x) / 2;
	p.y = (data->map->lines[yl - 1]->points[xl - 1]->y +
		data->map->lines[0]->points[0]->y) / 2;
	data->center = p;
}

void	change_x(data_t *data, int m_w)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j != data->map->len)
	{
		while (i != data->map->lines[j]->len)
		{
			data->map->lines[j]->points[i]->x = 
				data->map->lines[j]->points[i]->x + m_w;
			i++;
		}
		i = 0;
		j++;
	}
}

void	change_y(data_t *data, int m_h)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j != data->map->len)
	{
		while (i != data->map->lines[j]->len)
		{
			data->map->lines[j]->points[i]->y = 
				data->map->lines[j]->points[i]->y + m_h;
			i++;
		}
		i = 0;
		j++;
	}
}

void	projo(data_t *data, int y, int x)
{
	double X;
	double Y;
	double c;
	double v;

	c = 1;
	v = 0.75;
	X = c * data->map->lines[y]->points[x]->x - 
		data->map->lines[y]->points[x]->y * v;
	Y = (-1 * data->map->lines[y]->points[x]->h) + ((c / 2) * 
		data->map->lines[y]->points[x]->x) + ((v / 2) * 
		data->map->lines[y]->points[x]->y);
	data->map->lines[y]->points[x]->x = X;
	data->map->lines[y]->points[x]->y = Y;
}

void	adapt_map(data_t *data)
{
	int m_w;
	int m_h;

	center(data);
	m_w = (W_SIZE_W / 2) - data->center.x;
	m_h = (W_SIZE_H / 2) - data->center.y;
	change_x(data, m_w);
	change_y(data, m_h);
}
