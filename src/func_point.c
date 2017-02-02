/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:38:05 by ggregoir          #+#    #+#             */
/*   Updated: 2017/02/02 18:36:25 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_init_point(point_t *point, int x, int y, int color)
{
	point->x = x;
	point->y = y;
	point->color = color;
}

void			ft_swap_point(point_t *point1, point_t *point2)
{
	point_t tmp;

	tmp = *point1;
	*point1 = *point2;
	*point2 = tmp;
}

void 			ft_swap_x(point_t *point1, point_t *point2)
{
	point_t tmp;

	tmp.x = point1->x;
	point1->x = point2->x;
	point2->x = tmp.x;
}

void			d_projo(data_t *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j != data->map->len)
	{
		while (i != data->map->lines[j]->len)
		{
			projo(data, j, i);
			i++;
		}
		i = 0;
		j++;
	}
}