/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:08:53 by marvin            #+#    #+#             */
/*   Updated: 2018/12/13 17:15:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_tetri(t_tetri *list)
{
	while (list)
	{
		free(list->tetri);
		free(list);
		list = list->next;
	}
}

int		sum_link_matrix(int link_matrix[4][4])
{
	int		result;
	int		i;
	int		j;

	result = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result += link_matrix[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

int		check_neighbours(t_uchar matrix[4][4], int k, int l)
{
	int		link_count;

	link_count = 0;
	if (l + 1 < 4 && matrix[k][l + 1] == '#')
		link_count++;
	if (l - 1 > -1 && matrix[k][l - 1] == '#')
		link_count++;
	if (k + 1 < 4 && matrix[k + 1][l] == '#')
		link_count++;
	if (k - 1 > -1 && matrix[k - 1][l] == '#')
		link_count++;
	return (link_count);
}

int		check_linking(t_uchar matrix[4][4])
{
	int		link_matrix[4][4];
	int		i;
	int		j;

	i = 0;
	ft_init_array2_int(4, 4, link_matrix, 0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] == '#')
				link_matrix[i][j] = check_neighbours(matrix, i, j);
			j++;
		}
		i++;
	}
	return (sum_link_matrix(link_matrix) > 5);
}

int		check_valid(t_uchar matrix[4][4])
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return (count == 4 && check_linking(matrix));
}
