/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:20:45 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/02 14:02:26 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		adapt_color(point_t p1)
{
	if (p1.h < 0)
		return (0xCC0066);
	if (p1.h >= 0 && p1.h < 5)
		return (0xCC00CC);
	if (p1.h >= 5 && p1.h < 10)
		return (0xCC00FF);
	if (p1.h >= 10 && p1.h < 15)
		return (0x9900FF);
	if (p1.h >= 15 && p1.h < 25)
		return (0x6633CC);
	if (p1.h >= 25 && p1.h < 40)
		return (0x333399);
	if (p1.h >= 40 && p1.h < 80)
		return (0x0033CC);
	if (p1.h >= 80 && p1.h < 150)
		return (0x0000FF);
	if (p1.h >= 150 && p1.h < 250)
		return (0x0066FF);
	if (p1.h >= 250 && p1.h < 400)
		return (0x0099FF);
	if (p1.h >= 400 && p1.h < 650)
		return (0x00CCFF);
	if (p1.h >= 650 && p1.h < 900)
		return (0x00FFFF);
	return (0x66FFCC);
}

int		get_color(point_t p1, point_t p2)
{
	if (p1.h >= p2.h)
		return (adapt_color(p1));
	return (adapt_color(p2));
}
