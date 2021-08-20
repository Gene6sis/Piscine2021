/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 03:03:54 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/19 17:59:07 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write (1, "\n", 1);
}

int	ft_error(int *board, int x, int value)
{
	int	i;

	i = 1;
	while (x--)
	{
		if (board[x] == value)
			return (0);
		if ((board[x] == (value - i)) || (board[x] == (value + i)))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid(int *board, int x, int *compt)
{
	int	i;

	if (x == 10)
	{
		*compt += 1;
		ft_print(board);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (ft_error(board, x, i))
		{
			board[x] = i;
			ft_is_valid(board, x + 1, compt);
		}
		i++;
	}
	board[x] = -1;
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	board[10];
	int	compt;

	i = -1;
	while (++i < 10)
		board[i] = -1;
	compt = 0;
	ft_is_valid(board, 0, &compt);
	return (compt);
}

int main()
{
	ft_ten_queens_puzzle();
}
