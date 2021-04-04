/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejeong <sejeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:53:27 by sejeong           #+#    #+#             */
/*   Updated: 2021/04/04 20:58:19 by sejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_set(void);
int		helper(int (*board)[5], int row, int column, int *data);

int		check_argv(char *str, int data[])
{
	int		word_count;
	int		i;

	word_count = 0;
	i = 0;
	while (word_count < 16 && str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '0' || str[i] > '4')
				return (1);
			else
			{
				*data++ = str[i] - '0';
				word_count++;
			}
		}
		else if (str[i] != ' ' && str[i] < 9 && str[i] > 13)
			return (1);
		i++;
	}
	if (word_count == 16 && i == 31)
		return (0);
	else
		return (1);
}

int		check(int argc, char **argv, int *data)
{
	char *str;

	if (argc != 2)
		return (1);
	str = argv[1];
	if (check_argv(str, data))
		return (1);
	return (0);
}

void	print(int (*board)[5])
{
	int		i;
	int		j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			board[i][j] += '0';
			write(1, &board[i][j], 1);
			if (j == 4)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
		}
	}
}

int		main(int argc, char **argv)
{
	int		data[16];
	int		board[5][5];

	if (check(argc, argv, data))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_set();
	if (helper(board, 1, 1, data))
	{
		print(board);
	}
	else
		write(1, "Error\n", 6);
}
