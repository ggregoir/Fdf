/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:03:19 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/06 15:21:33 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_exit(void)
{
	exit(1);
}

void	malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	fdf_exit();
}

void	map_error(void)
{
	ft_putstr_fd("map error\n", 2);
	fdf_exit();
}

void	arg_error(void)
{
	ft_putstr_fd("Un seul argument pris en compte.\n", 2);
	fdf_exit();
}
