/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:58:37 by ggregoir          #+#    #+#             */
/*   Updated: 2017/01/28 15:25:36 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# define BUFF_SIZE		1000
# define SIZE_W 20
# define SIZE_H 20

typedef struct	point_s
{
	int			x;
	int			y;
	int			h;
	int			color;
	int 		h_color;
}				point_t;

typedef struct	lines_s
{
	point_t **points;
	int		len;
}				lines_t;

typedef struct	map_s
{
	lines_t	**lines;
	int		len;
}				map_t;

typedef struct	data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	map_t		*map;
}				data_t;

void			ft_swap_point(point_t *point1, point_t *point2);
int				ft_draw_line_case2(point_t i, point_t j, data_t data);
int				ft_draw_line_case1(point_t i, point_t j, data_t data);
int				ft_draw_line(point_t i, point_t j, data_t data);
void			ft_draw(data_t data, point_t point);
void			ft_init_point(point_t *point, int x, int y, int color);
void			ft_swap_point(point_t *point1, point_t *point2);
int				get_next_line(const int fd, char **line);
map_t			*read_map(char ** argv, int fd);
int				getnb(char *str);
int				ft_pts(char *line, int nb_lines, point_t ***points);
int				ft_nb_lines(char *line);
void			fdf_exit(void);
void			malloc_error(void);
void			map_error(void);
void			arg_error(void);




#endif