/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:07:47 by ggregoir          #+#    #+#             */
/*   Updated: 2017/01/23 18:27:47 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, data_t data)
{
	if (!data.mlx_ptr)
		data.mlx_ptr = 0;
	if (keycode == 53)
	{
		//mlx_destroy_window(data.mlx_ptr, data.mlx_win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	data_t		data;


	if(argc == 2)
	{
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 1280, 720, "FDF")) == NULL)
		return (EXIT_FAILURE);
	read_map(argv, 0);
	mlx_key_hook(data.mlx_win, key_hook, 0);
	mlx_loop(data.mlx_ptr);
	}
	ft_putstr("usage: ./fdf [map]\n");
	return 0;
}
