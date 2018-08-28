/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 18:04:07 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 08:40:28 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# define ARG_ERR "\x1b[31mWrong number of arguments | usage : ./fdf maps.fdf\n"
# define LINE_ERR "\x1b[31mFound wrong line length, program now Exiting\n"
# define DATA_ERR "\x1b[31mNo data found.\n"
# define ABS(n) (n > 0 ? n : -n)
# define P_ERR "\x1b[31mError "
# define L_ERR -2
# include "./libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "fdf.h"

typedef struct	s_fd
{
	int			fd;
	int			ret;
}				t_fd;

#endif
