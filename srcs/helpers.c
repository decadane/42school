/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:45:58 by marvin            #+#    #+#             */
/*   Updated: 2018/12/13 15:38:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_uchar	**alloc_memory(int size)
{
	t_uchar	**result;
	int		i;

	i = 1;
	result = (t_uchar**)malloc(size * sizeof(t_uchar*) + size *
			size * sizeof(t_uchar));
	result[0] = (t_uchar*)(result + size);
	while (i < size)
	{
		result[i] = result[0] + i * size;
		i++;
	}
	ft_init_array2_uchar(size, size, result, 0);
	return (result);
}

void	copy_field(t_uchar **field, t_uchar **new_field, int size)
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

void	print_array_uchar(t_uchar **matrix, int width, int height)
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
