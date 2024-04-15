/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:10:34 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/24 14:10:36 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid(char row, int col, char *board)
{
	int		diff;
	char	compare_cell;

	diff = 1;
	while (col - diff >= 0)
	{
		compare_cell = board[col - diff];
		if (compare_cell == row
			|| compare_cell - diff == row
			||compare_cell + diff == row
			|| row < '0' || row > '9'
		)
		{
			return (0);
		}
		diff++;
	}
	return (1);
}

int	solve(int col, char *board, int *count)
{
	char	row;

	row = '0';
	while (row >= '0' && row <= '9')
	{
		if (valid(row, col, board))
		{
			board[col] = row;
			solve(col + 1, board, count);
		}
		row++;
	}
	if (col == 9 && valid(board[9], col, board))
	{
		write(1, board, 10);
		write(1, "\n", 1);
		*count += 1;
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		count;

	count = 0;
	solve(0, board, &count);
	return (count);
}

/*
#include <stdio.h>
int main(void)
{
	int count = ft_ten_queens_puzzle();
	printf("Total count is: %d", count);
}
*/