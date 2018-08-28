/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:22:41 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 09:23:17 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "gfx.h"

typedef struct	s_array
{
	char		**matrix;
	char		*link_rows;
	char		*row;
	int			ret;
	long		count;
	long		i;
}				t_array;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			i;
}				t_mlx;

typedef struct	s_dda
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			z1;
	int			z2;
	double		scale;
}				t_dda;

typedef	struct	s_inc
{
	int			i;
	int			steps;
	double		x_inc;
	double		y_inc;
	double		z_inc;
}				t_inc;

typedef	struct	s_pixel
{
	int			dif_x;
	int			dif_y;
	int			dif_z;
	float		x;
	float		y;
	float		z;
	int			steps;
}				t_pixel;

typedef struct	s_sum
{
	char		***val;
	double		z_axis;
	int			x;
	int			y;
}				t_sum;

void			draw_y_pixels(t_sum *plot, t_dda *pixel,
				t_mlx *mlx, t_array *row);
int				draw_xy_pixels(t_sum *plot, t_array *row, t_mlx *mlx);
char			*strjoin_free(char const *s1, char const *s2);
void			dda_algo(t_dda *draw, t_mlx *mlx, double z);
int				draw_pixels(t_mlx *mlx, t_array *matrix);
int				dda_sum(t_pixel *add, t_dda *point);
int				get_matrix(t_array *n_row, int fd);
int				wire_frame(int fd);
void			window(t_mlx *mlx);
int				esc_fun(int key);

#endif
