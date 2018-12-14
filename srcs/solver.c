/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:24:39 by marvin            #+#    #+#             */
/*   Updated: 2018/12/14 17:03:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		output(int size, t_uchar cur_field[size][size],
		t_uchar field[size][size], int *flag)
{
	copy_field(size, cur_field, field);
	*flag = 1;
	print_array_uchar(size, size, cur_field);
	return (*flag);
}

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

int		sum_arrays(t_tetri *list, int size,
		t_uchar cur_field[size][size], int params[2])
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

int		solver(t_tetri *list, int size, t_uchar field[size][size], int *flag)
{
	t_uchar	cur_field[size][size];
	int		params[2];

	params[0] = -1;
	ft_init_array2_uchar(size, size, cur_field, 0);
	while (++params[0] < size - list->height + 1)
	{
		params[1] = -1;
		while (++params[1] < size - list->width + 1)
		{
			copy_field(size, field, cur_field);
			if (sum_arrays(list, size, cur_field, params))
			{
				if (list->next == NULL)
				{
					output(size, cur_field, field, flag);
				}
				else
					solver(list->next, size, cur_field, flag);
			}
			if (*flag)
				return (1);
		}
	}
	return (*flag);
}

int		prepare_to_solve(t_tetri *list, int size)
{
	int		i;
	t_uchar	field[size][size];
	int		flag;

	flag = 0;
	ft_init_array2_uchar(size, size, field, 0);
	i = 1;
	while (!flag)
	{
		if (solver(list, size, field, &flag))
			break ;
		prepare_to_solve(list, size + 1);
		return (0);
	}
	return (1);
}
