/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:29:01 by marvin            #+#    #+#             */
/*   Updated: 2018/12/13 15:26:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			complete_matrix(char *str, t_uchar matrix[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = str[i * 5 + j];
			j++;
		}
		i++;
	}
	return (check_valid(matrix));
}

int			read_tetris(int fd, t_uchar matrix[4][4])
{
	char	str[21];
	int		i;
	int		len;
	int		flag;

	flag = 1;
	len = read(fd, str, 21);
	i = 1;
	while (i <= len)
	{
		if (str[i - 1] == '.' || str[i - 1] == '#' || (str[i - 1] == '\n'
					&& (i % 5 == 0 || i == 21)))
			i++;
		else
			return (0);
	}
	if (len == 20)
		flag = -1;
	return (complete_matrix(str, matrix) * flag);
}
