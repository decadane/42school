/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:50:41 by marvin            #+#    #+#             */
/*   Updated: 2018/12/13 17:14:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define MAX(x, y) x > y ? x : y

typedef unsigned char	t_uchar;

typedef struct			s_tetrimino
{
	int					width;
	int					height;
	t_uchar				**tetri;
	struct s_tetrimino	*next;
}						t_tetri;

int						complete_matrix(char *str, t_uchar matrix[4][4]);
int						read_tetris(int fd, t_uchar matrix[4][4]);
int						sum_link_matrix(int link_matrix[4][4]);
int						check_neighbours(t_uchar matrix[4][4], int k, int l);
int						check_linking(t_uchar matrix[4][4]);
int						check_valid(t_uchar matrix[4][4]);
void					clean_tetri(t_tetri *list);

t_tetri					*write_new_tetri(t_tetri *list, t_uchar matrix[4][4]);
t_uchar					**trim_tetri(t_uchar matrix[4][4], int params[4],
		int tetri_count);

void					print_array_uchar(t_uchar **matrix, int width,
		int height);
void					print_tetris(t_tetri *list);
int						list_count(t_tetri *list);
void					copy_field(t_uchar **field, t_uchar
		**new_field, int size);
t_uchar					**alloc_memory(int size);
int						find_max_count(t_tetri *list);

int						prepare_to_solve(t_tetri *list);
t_uchar					**solver(t_tetri *list, int size);
int						sum_arrays(t_tetri *list, int size, t_uchar field[size][size],
		int params[2]);

#endif
