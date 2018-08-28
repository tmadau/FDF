/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:49:51 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 08:49:56 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_pixels(t_mlx *mlx, t_array *matrix)
{
	int		n;
	t_sum	plot;

	n = 0;
	if (!(plot.val = (char ***)malloc(sizeof(plot.val) * 3)))
		return (0);
	plot.val[2] = NULL;
	draw_xy_pixels(&plot, matrix, mlx);
	free(plot.val);
	return (1);
}

int		wire_frame(int fd)
{
	t_array	matrix;
	t_mlx	mlx;
	int		n;

	if ((n = get_matrix(&matrix, fd)) != 1)
		return (n);
	window(&mlx);
	draw_pixels(&mlx, &matrix);
	mlx_key_hook(mlx.win, esc_fun, 0);
	mlx_loop(mlx.mlx);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fd	draw;

	if (argc == 2)
	{
		draw.fd = open(argv[1], O_RDONLY);
		if (draw.fd != ERR)
		{
			draw.ret = wire_frame(draw.fd);
			if (draw.ret == 0)
				ft_putstr("FAILURE\n");
			draw.ret == L_ERR ? ft_putstr(LINE_ERR) : ft_putstr(DATA_ERR);
		}
		else
		{
			perror(P_ERR);
			return (ERR);
		}
		close(draw.fd);
	}
	else
		ft_putstr(ARG_ERR);
	return (0);
}
