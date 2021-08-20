/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:26:27 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/15 00:27:50 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_is_in_row(int value, int **board, int y, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (board[y][i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_row_valid_right(int **board, int *condition, int row, int num)
{
	int	max;
	int	view;
	int	i;

	max = 0;
	view = 0;
	i = 0;
	while (i < num)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			view++;
		}
		if (board[row][i] == 0)
			return (-1);
		i++;
	}
	if (condition[row + (num * 2)] != view)
		return (0);
	return (1);
}

int	ft_is_row_valid_left(int **board, int *condition, int row, int num)
{
	int	max;
	int	view;
	int	i;

	i = num - 1;
	max = 0;
	view = 0;
	while (i >= 0)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			view++;
		}
		if (board[row][i] == 0)
			return (-1);
		i--;
	}
	if (condition[row + (num * 3)] != view)
		return (0);
	return (1);
}

int	ft_checkrow(int **board, int *cond, int x, int num)
{
	if (ft_is_row_valid_left(board, cond, x, num)
		&& ft_is_row_valid_right(board, cond, x, num))
		return (1);
	return (0);
}
