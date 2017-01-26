/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:58:37 by ggregoir          #+#    #+#             */
/*   Updated: 2017/01/23 18:35:09 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# define BUFF_SIZE		1000

typedef struct	data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
}				data_t;

typedef struct	point_s
{
	int			x;
	int			y;
	int			color;
}				point_t;

typedef struct	verif_s
{
	int		mx;
	int		my;
	int		x;
	int		y;
	int		p;
	
}				verif_t;

void			ft_swap_point(point_t *point1, point_t *point2);
int				ft_draw_line_case2(point_t i, point_t j, data_t data);
int				ft_draw_line_case1(point_t i, point_t j, data_t data);
int				ft_draw_line(point_t i, point_t j, data_t data);
void			ft_draw(data_t data, point_t point);
void			ft_init_point(point_t *point, int x, int y, int color);
void			ft_swap_point(point_t *point1, point_t *point2);
int				get_next_line(const int fd, char **line);
char			**read_map(char ** argv);
int				verif_count(char **map, verif_t *v);




#endif