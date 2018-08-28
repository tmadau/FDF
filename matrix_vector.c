/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:35:58 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 08:54:53 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*strjoin_free(char const *s1, char const *s2)
{
	t_array		string;

	if (!s1 || !s2)
		return (NULL);
	string.i = 0;
	string.count = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2;
	if (!(string.row = (char *)malloc(sizeof(char) * string.count)))
		return (NULL);
	if (s1 && s2)
	{
		string.row[string.i] = '\0';
		ft_strlcat(string.row, s1, string.count);
		ft_strlcat(string.row, ")", string.count);
		ft_strlcat(string.row, s2, string.count);
	}
	free((void *)s1);
	return (string.row);
}

int		get_matrix(t_array *n_row, int fd)
{
	n_row->row = NULL;
	n_row->link_rows = NULL;
	n_row->count = -1;
	n_row->i = 0;
	while ((n_row->ret = get_next_line(fd, &n_row->row)) > 0)
	{
		if (!n_row->link_rows)
			n_row->link_rows = ft_strdup("");
		if (n_row->count == -1)
			n_row->count = ft_wordcount(n_row->row, ' ');
		else if (n_row->count != (long)ft_wordcount(n_row->row, ' '))
		{
			ft_strdel(&n_row->link_rows);
			return (-2);
		}
		n_row->link_rows = strjoin_free(n_row->link_rows, n_row->row);
		ft_strdel(&n_row->row);
		n_row->i++;
	}
	if (n_row->count == 0 || n_row->ret == -1)
		return (-3);
	n_row->matrix = ft_strsplit(n_row->link_rows, ')');
	ft_strdel(&n_row->link_rows);
	return (1);
}
