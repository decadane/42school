/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:24:39 by marvin            #+#    #+#             */
/*   Updated: 2018/12/13 17:31:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checker(int size, t_uchar field[size][size])
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((field[i][j] > 'Z' || field[i][j] < 'A') && field[i][j] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		sum_arrays(t_tetri *list, int size, t_uchar cur_field[size][size], int params[2])
{
	int		i;
	int		j;

	i = 0;
	while (i < list->height)
	{
		j = 0;
		while (j < list->width)
		{
			cur_field[params[0] + i][params[1] + j] += list->tetri[i][j];
			j++;
		}
		i++;
	}
	return (checker(size, cur_field));
}

t_uchar	**solver(t_tetri *list, int size)
{
	t_uchar	field[size][size];
	t_uchar	result[size][size];
	int		params[2];

	params[0] = -1;
	while (++params[0] < size - list->height + 1)
	{
		params[1] = -1;
		while (++params[1] < size - list->width + 1)
		{
			if (sum_arrays(list, size, field, params))
			{
				if (list->next == NULL)
					result = field;
				else
					result = solver(list->next, size);
			}
		}
	}
	print_array_uchar(result, size, size);
	return (result);
}

int		prepare_to_solve(t_tetri *list)
{
	int		size;
	int		i;

	i = 1;
	size = MAX(ft_sqrt(list_count(list) * 4), find_max_count(list));
	while (1)
	{
		result = solver(list, size);
		if (result)
			break ;
		size++;
	}
	return (0);
}
