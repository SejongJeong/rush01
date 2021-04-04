/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeong <sejeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:54:29 by sejeong           #+#    #+#             */
/*   Updated: 2021/04/04 20:56:42 by sejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		valid_down(int (*board)[5], int *data)
{
	int		i;
	int		j;
	int		cnt;
	int		line_max;

	i = 0;
	while (++i < 5)
	{
		cnt = 0;
		line_max = 0;
		j = 0;
		while (++j < 5)
		{
			if (line_max < board[j][i])
			{
				line_max = board[j][i];
				cnt++;
			}
		}
		if (cnt != data[i - 1] && data[i - 1] != 0)
			return (0);
	}
	return (1);
}

int		valid_up(int (*board)[5], int *data)
{
	int		i;
	int		j;
	int		cnt;
	int		line_max;

	i = 0;
	while (++i < 5)
	{
		cnt = 0;
		line_max = 0;
		j = 0;
		while (++j < 5)
		{
			if (line_max < board[5 - j][i])
			{
				line_max = board[5 - j][i];
				cnt++;
			}
		}
		if (cnt != data[i + 3] && data[i + 3] != 0)
			return (0);
	}
	return (1);
}

int		valid_right(int (*board)[5], int *data)
{
	int		i;
	int		j;
	int		cnt;
	int		line_max;

	i = 0;
	while (++i < 5)
	{
		cnt = 0;
		line_max = 0;
		j = 0;
		while (++j < 5)
		{
			if (line_max < board[i][j])
			{
				line_max = board[i][j];
				cnt++;
			}
		}
		if (cnt != data[i + 7] && data[i + 7] != 0)
			return (0);
	}
	return (1);
}

int		valid_left(int (*board)[5], int *data)
{
	int		i;
	int		j;
	int		cnt;
	int		line_max;

	i = 0;
	while (++i < 5)
	{
		cnt = 0;
		line_max = 0;
		j = 0;
		while (++j < 5)
		{
			if (line_max < board[i][5 - j])
			{
				line_max = board[i][5 - j];
				cnt++;
			}
		}
		if (cnt != data[i + 11] && data[i + 11] != 0)
			return (0);
	}
	return (1);
}

int		is_valid(int (*board)[5], int *data)
{
	if (!valid_down(board, data))
		return (0);
	if (!valid_up(board, data))
		return (0);
	if (!valid_right(board, data))
		return (0);
	if (!valid_left(board, data))
		return (0);
	return (1);
}
