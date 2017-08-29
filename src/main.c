/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:07:47 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/17 22:36:24 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int keycode, data_t data)
{
	if (!data.mlx_ptr)
		data.mlx_ptr = 0;
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

void	verif_line(data_t data)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (i != data.map->len)
	{
		if (j < 0)
			j = data.map->lines[i]->len;
		if (j != data.map->lines[i]->len)
			map_error();
		i++;
	}
}

int		main(int argc, char **argv)
{
	data_t		data;

	data.cte1 = 0.80;
	data.cte2 = 1;
	if (argc == 2)
	{
		if ((data.mlx_ptr = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		if ((data.mlx_win =
			mlx_new_window(data.mlx_ptr, W_SIZE_W, W_SIZE_H, "FDF")) == NULL)
			return (EXIT_FAILURE);
		data.map = read_map(argv, 0, &data);
		verif_line(data);
		d_projo(&data);
		adapt_map(&data);
		ft_draw_map(data);
		mlx_key_hook(data.mlx_win, key_hook, 0);
		mlx_loop(data.mlx_ptr);
	}
	ft_putstr("usage: ./fdf [map]\n");
	return (0);
}
