/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:45:58 by marvin            #+#    #+#             */
/*   Updated: 2018/12/14 16:50:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	copy_field(int size, t_uchar field[size][size],
		t_uchar new_field[size][size])
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			new_field[i][j] = field[i][j];
			j++;
		}
		i++;
	}
}

void	print_array_uchar(int width, int height, t_uchar matrix[width][height])
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (matrix[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(matrix[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int		list_count(t_tetri *list)
{
	int		count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

int		find_max_count(t_tetri *list)
{
	int		result;

	result = 0;
	while (list)
	{
		if (list->width > result)
			result = list->width;
		if (list->height > result)
			result = list->height;
		list = list->next;
	}
	return (result);
}
