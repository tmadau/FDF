/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:47:09 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/17 12:37:45 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		esc_fun(int key)
{
	if (key == 12 || key == 53)
	{
		ft_putendl_fd("\e\x1b[31mwindow closed!", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1850, 1030, "FDF");
}
