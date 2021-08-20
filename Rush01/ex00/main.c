/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 00:30:28 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/15 19:20:03 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_is_valid(int **board, int *cd, int pos, int n)
{
	int	x;
	int	y;
	int	i;

	if (pos == (n * n))
		return (1);
	x = pos / n;
	y = pos % n;
	if (board[x][y] != 0)
		return (ft_is_valid(board, cd, pos + 1, n));
	i = 0;
	while (++i < (n + 1))
	{
		if (!ft_is_in_col(i, board, y, n) && !ft_is_in_row(i, board, x, n))
		{
			board[x][y] = i;
			if (ft_checkcol(board, cd, y, n) && ft_checkrow(board, cd, x, n))
			{
				if (ft_is_valid(board, cd, pos + 1, n))
					return (1);
			}
		}
	}
	board[x][y] = 0;
	return (0);
}

int	isokformat(int argc, char **argv)
{
	int	num;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	num = (ft_strlen(argv[1]) + 1) / 8;
	if (!is_correct_format(argv[1], num))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*conditions;
	int	**board;
	int	num;

	if (!isokformat(argc, argv))
		return (0);
	num = (ft_strlen(argv[1]) + 1) / 8;
	conditions = num_str_to_int(argv[1], num);
	board = ft_create_board(num);
	if (board == NULL)
		return (0);
	if (ft_is_valid(board, conditions, 0, num))
		ft_print_board(board, num);
	else
		write(1, "Error\n", 6);
	ft_free_board(board, num);
	free(conditions);
	return (0);
}
