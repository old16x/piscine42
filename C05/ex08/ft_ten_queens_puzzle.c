/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:56:12 by aradix            #+#    #+#             */
/*   Updated: 2023/09/20 21:07:34 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_board(char *board)
{
	int	i;
	int	j;

	i = 0;
	while (board[i] && board[i] != '.')
	{
		j = i + 1;
		while (board[j] && board[j] != '.')
		{
			if ((board[i] == board[j]) || (board[i] == board[j] - (j - i))
				|| (board[i] == board[j] + (j - i)))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	print_board(char *board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		write(1, &board[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	solver(char *board, int i, char value, int *counter)
{
	char	c;

	if (i == 10 && check_board(board))
	{
		print_board(board);
		(*counter)++;
		return ;
	}
	if (value >= '0' && value <= '9')
	{
		c = board[i];
		board[i] = value;
		if (check_board(board))
		{
			board[i] = value;
			solver(board, i + 1, '0', counter);
			board[i] = '.';
		}
		else
			board[i] = c;
		if (value < '9')
			solver(board, i, value + 1, counter);
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[11];
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < 10)
	{
		board[i] = '.';
		i++;
	}
	board[10] = '\0';
	solver(board, 0, '0', &ret);
	return (ret);
}
