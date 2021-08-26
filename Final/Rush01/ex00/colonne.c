/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:12:58 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/15 00:26:16 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_is_in_col(int value, int **board, int x, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (board[i][x] == value)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_col_valid_down(int **board, int *condition, int col, int num)
{
	int	max;
	int	view;
	int	i;

	max = 0;
	view = 0;
	i = 0;
	while (i < num)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			view++;
		}
		if (board[i][col] == 0)
			return (-1);
		i++;
	}
	if (condition[col] != view)
		return (0);
	return (1);
}

int	ft_is_col_valid_up(int **board, int *condition, int col, int num)
{
	int	max;
	int	view;
	int	i;

	i = num - 1;
	max = 0;
	view = 0;
	while (i >= 0)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			view++;
		}
		if (board[i][col] == 0)
			return (-1);
		i--;
	}
	if (condition[col + num] != view)
		return (0);
	return (1);
}

int	ft_checkcol(int **board, int *cond, int y, int num)
{
	if (ft_is_col_valid_down(board, cond, y, num)
		&& ft_is_col_valid_up(board, cond, y, num))
		return (1);
	return (0);
}
