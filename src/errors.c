/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:56:10 by ggregoir          #+#    #+#             */
/*   Updated: 2017/01/28 13:08:55 by ggregoir         ###   ########.fr       */
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