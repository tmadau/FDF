/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:32:05 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 09:20:40 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		dda_sum(t_pixel *add, t_dda *point)
{
	add->dif_x = point->x2 - point->x1;
	add->dif_y = point->y2 - point->y1;
	add->dif_z = point->z2 - point->z1;
	if (ABS(add->dif_x) >= ABS(add->dif_z))
		ABS(add->dif_x) >= ABS(add->dif_y) ? add->steps = ABS(add->dif_x)
			: (add->steps = ABS(add->dif_y));
	else
		ABS(add->dif_z) >= ABS(add->dif_y) ? add->steps = ABS(add->dif_z)
			: (add->steps = ABS(add->dif_y));
	add->x = point->x1;
	add->y = point->y1;
	add->z = point->z1;
	return (add->steps);
}

void	dda_algo(t_dda *draw, t_mlx *mlx, double z)
{
	t_pixel	set;
	t_inc	put;

	(void)z;
	put.steps = dda_sum(&set, draw);
	put.x_inc = set.dif_x / (float)put.steps;
	put.y_inc = set.dif_y / (float)put.steps;
	put.z_inc = set.dif_z / (float)put.steps;
	put.i = 0;
	while (put.i <= put.steps)
	{
		if (set.z > 0)
			mlx_pixel_put(mlx->mlx, mlx->win, (set.x - set.y)
					+ 800, (set.x + set.y) / 2 + 100 + set.z, 0xadff2f);
		else if (set.z < 0)
			mlx_pixel_put(mlx->mlx, mlx->win, (set.x - set.y)
					+ 800, (set.x + set.y) / 2 + 100 + set.z, 0xffd700);
		else
			mlx_pixel_put(mlx->mlx, mlx->win, (set.x - set.y)
					+ 800, (set.x + set.y) / 2 + 100 + set.z, 0xbc8f8f);
		set.x += put.x_inc;
		set.y += put.y_inc;
		set.z += put.z_inc;
		put.i++;
	}
}

void	draw_y_pixels(t_sum *plot, t_dda *pixel, t_mlx *mlx, t_array *row)
{
	mlx->i = 0;
	if ((plot->val[1] = ft_strsplit(row->matrix[plot->y + 1], ' ')))
	{
		pixel->x1 = 0;
		pixel->x2 = 0;
		plot->x = -1;
		while (plot->val[0][++plot->x] && plot->val[1][plot->x])
		{
			pixel->z1 = (-1 * (double)ft_atoi(plot->val[0][plot->x]));
			pixel->z2 = (-1 * (double)ft_atoi(plot->val[1][plot->x]));
			pixel->y1 = (pixel->scale * plot->y);
			pixel->y2 = (pixel->scale * (plot->y + 1));
			dda_algo(pixel, mlx, plot->z_axis);
			pixel->x2 += pixel->scale;
			pixel->x1 = pixel->x2;
		}
		mlx->i = -1;
		while (++mlx->i < row->count)
			free(plot->val[1][mlx->i]);
	}
	plot->x = 0;
	plot->y++;
	mlx->i = -1;
	while (++mlx->i < row->count)
		free(plot->val[0][mlx->i]);
}

int		draw_xy_pixels(t_sum *plot, t_array *row, t_mlx *mlx)
{
	t_dda	pixel;

	pixel.scale = 21;
	plot->y = 0;
	plot->x = 0;
	while (row->matrix[plot->y] && !(pixel.x1 = 0))
	{
		plot->val[0] = ft_strsplit(row->matrix[plot->y], ' ');
		pixel.x2 = pixel.scale;
		while (plot->val[0][plot->x] && plot->val[0][plot->x + 1])
		{
			pixel.z1 = (-1 * (double)ft_atoi(plot->val[0][plot->x]));
			pixel.z2 = (-1 * (double)ft_atoi(plot->val[0][plot->x + 1]));
			pixel.y1 = (pixel.scale * plot->y);
			pixel.y2 = (pixel.scale * (plot->y));
			dda_algo(&pixel, mlx, plot->z_axis);
			pixel.x1 = pixel.x2;
			pixel.x2 += pixel.scale;
			plot->x++;
		}
		draw_y_pixels(plot, &pixel, mlx, row);
		free(plot->val[0]);
		free(plot->val[1]);
	}
	return (0);
}
