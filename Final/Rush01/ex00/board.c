/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:48:05 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/15 00:21:27 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>
#include <unistd.h>

int	**ft_create_board(int num)
{
	int	**board;
	int	i;
	int	j;

	board = malloc(sizeof(int *) * num);
	if (!board)
		return (NULL);
	i = 0;
	while (i < num)
	{
		board[i] = malloc(sizeof(int) * num);
		if (!board[i])
			return (NULL);
		i++;
	}
	i = -1;
	while (++i < num)
	{
		j = -1;
		while (++j < num)
			board[i][j] = 0;
	}
	return (board);
}

void	ft_print_board(int **board, int num)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j != (num - 1))
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_free_board(int **board, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
