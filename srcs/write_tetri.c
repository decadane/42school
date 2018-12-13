/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:25:10 by marvin            #+#    #+#             */
/*   Updated: 2018/12/13 15:28:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_uchar	**create_tetri(int width, int height)
{
	int		i;
	t_uchar	**result;

	i = 1;
	result = (t_uchar**)malloc(height * sizeof(t_uchar*) + width *
			height * sizeof(t_uchar));
	result[0] = (t_uchar*)(result + height);
	while (i < height)
	{
		result[i] = result[0] + i * width;
		i++;
	}
	return (result);
}

void	count_params(t_uchar matrix[4][4], int params[4])
{
	int		i;
	int		j;

	i = 0;
	ft_init_array1(4, params, -1);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] == '#')
			{
				i < params[0] || params[0] == -1 ? params[0] = i : 0;
				i > params[1] ? params[1] = i : 0;
				j < params[2] || params[2] == -1 ? params[2] = j : 0;
				j > params[3] ? params[3] = j : 0;
			}
			j++;
		}
		i++;
	}
}

t_uchar	**trim_tetri(t_uchar matrix[4][4], int params[4], int tetri_count)
{
	int		i;
	int		j;
	int		width;
	int		height;
	t_uchar	**result;

	i = 0;
	width = params[3] - params[2] + 1;
	height = params[1] - params[0] + 1;
	result = create_tetri(width, height);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (matrix[i + params[0]][j + params[2]] == '#')
				result[i][j] = 'A' + tetri_count;
			else
				result[i][j] = 0;
			j++;
		}
		i++;
	}
	return (result);
}

void	write_params(t_tetri *cur, int params[4],
		t_uchar matrix[4][4], int tetri_count)
{
	cur->width = params[3] - params[2] + 1;
	cur->height = params[1] - params[0] + 1;
	cur->next = NULL;
	cur->tetri = trim_tetri(matrix, params, tetri_count);
}

t_tetri	*write_new_tetri(t_tetri *list, t_uchar matrix[4][4])
{
	int		params[4];
	t_tetri	*head;
	int		tetri_count;

	head = list;
	tetri_count = 1;
	count_params(matrix, params);
	if (!list)
	{
		tetri_count = 0;
		list = (t_tetri*)malloc(sizeof(t_tetri));
		head = list;
	}
	else
	{
		while (list->next)
		{
			tetri_count++;
			list = list->next;
		}
		list->next = (t_tetri*)malloc(sizeof(t_tetri));
		list = list->next;
	}
	write_params(list, params, matrix, tetri_count);
	return (head);
}
