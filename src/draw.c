/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:32:16 by ggregoir          #+#    #+#             */
/*   Updated: 2017/01/18 20:50:56 by ggregoir         ###   ########.fr       */
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
					* (y - i.y) / (j.y - i.y)), y, 0xff0000);
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
					* (x - i.x) / (j.x - i.x)), 0xff0000);
		x++;
	}
	return (0);
}

int				ft_draw_line(point_t i, point_t j, data_t data)
{
	if (labs(j.x - i.x) >= labs(j.y - i.y))
	{
		if (i.x < j.x)
			ft_draw_line_case1(i, j, data);
		else
			ft_draw_line_case1(j, i, data);
	}
	else if (labs(j.x - i.x) < labs(j.y - i.y))
	{
		if (i.x < j.x)
			ft_draw_line_case2(i, j, data);
		else
			ft_draw_line_case2(j, i, data);
	}
	return (0);
}