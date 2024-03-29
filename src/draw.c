/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:32:16 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/02 13:38:03 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_draw(data_t data, point_t point)
{
	mlx_pixel_put(data.mlx_ptr, data.mlx_win, point.x, point.y, point.color);
}

int				ft_draw_line_case2(point_t i, point_t j, data_t data)
{
	int			y;

	if (i.y >= j.y)
	{
		ft_swap_point(&i, &j);
	}
	y = i.y;
	while (y <= j.y && j.y != i.y)
	{
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, i.x + ((j.x - i.x)
					* (y - i.y) / (j.y - i.y)), y, get_color(i, j));
		y++;
	}
	return (0);
}

int				ft_draw_line_case1(point_t i, point_t j, data_t data)
{
	int			x;

	if (i.x >= j.x)
	{
		ft_swap_point(&i, &j);
	}
	x = i.x;
	while (x <= j.x && j.x != i.x)
	{
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, i.y + ((j.y - i.y)
					* (x - i.x) / (j.x - i.x)), get_color(i, j));
		x++;
	}
	return (0);
}

int				ft_draw_line(point_t i, point_t j, data_t data)
{
	if (fabs(j.x - i.x) >= fabs(j.y - i.y))
	{
		if (i.x < j.x)
			ft_draw_line_case1(i, j, data);
		else
			ft_draw_line_case1(j, i, data);
	}
	else if (fabs(j.x - i.x) < fabs(j.y - i.y))
	{
		if (i.x < j.x)
			ft_draw_line_case2(i, j, data);
		else
			ft_draw_line_case2(j, i, data);
	}
	return (0);
}

void			ft_draw_map(data_t data)
{
	data.di = 0;
	data.dj = 0;
	while (data.di != data.map->lines[0]->len)
	{
		while (data.dj != data.map->len - 1)
		{
			ft_draw_line(*data.map->lines[data.dj]->points[data.di],
				*data.map->lines[data.dj + 1]->points[data.di], data);
			data.dj++;
		}
		data.dj = 0;
		data.di++;
	}
	data.di = 0;
	while (data.dj != data.map->len)
	{
		while (data.di != data.map->lines[0]->len - 1)
		{
			ft_draw_line(*data.map->lines[data.dj]->points[data.di],
				*data.map->lines[data.dj]->points[data.di + 1], data);
			data.di++;
		}
		data.di = 0;
		data.dj++;
	}
}
