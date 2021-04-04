/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeong <sejeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:54:24 by sejeong           #+#    #+#             */
/*   Updated: 2021/04/04 21:51:06 by sejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

int		g_set_row[5][5];
int		g_set_col[5][5];

void	set_board(int (*board)[5], int row, int column, int num)
{
	board[row][column] = num;
	g_set_row[row][num] = 1;
	g_set_col[column][num] = 1;
}

void	unset(int row, int column, int num)
{
	g_set_row[row][num] = 0;
	g_set_col[column][num] = 0;
}

int		helper(int (*board)[5], int row, int column, int *data)
{
	int		next_num;

	if (row == 5 && is_valid(board, data))
		return (1);
	else if (row == 5)
		return (0);
	if (column == 5)
		return (helper(board, row + 1, 1, data));
	next_num = 0;
	while (++next_num < 5)
	{
		if (g_set_row[row][next_num] || g_set_col[column][next_num])
			continue;
		set_board(board, row, column, next_num);
		if (helper(board, row, column + 1, data))
			return (1);
		unset(row, column, next_num);
	}
	return (0);
}

void	init_set(void)
{
	int		i;
	int		j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			g_set_row[i][j] = 0;
			g_set_col[i][j] = 0;
		}
	}
}
