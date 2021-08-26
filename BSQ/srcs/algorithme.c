/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:52:11 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/25 22:00:44 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"

int	minbetween(int top, int left, int topleft)
{
	int	res;

	res = left;
	if (res > topleft)
		res = topleft;
	if (res > top)
		res = top;
	return (res + 1);
}

int	algorithme(int **tab, t_info *info, int *x, int *y)
{
	int	i;
	int	j;
	int	max;

	if (!tab)
		return (0);
	i = 0;
	max = 0;
	while (++i < info->row)
	{
		j = 0;
		while (++j < info->col)
		{
			if (tab[i][j] != 0)
				tab[i][j] = minbetween(tab[i - 1][j], tab[i][j - 1],
						tab[i - 1][j - 1]);
			if (tab[i][j] > max)
			{
				max = tab[i][j];
				*y = i;
				*x = j;
			}
		}
	}
	return (max);
}

int	**creategrid(char ***tab, t_info *info)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc(sizeof(int *) * (info->row + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < info->row)
	{
		grid[i] = malloc(sizeof(int) * (info->col + 1));
		if (!grid[i])
			return (NULL);
		j = 0;
		while (j < info->col)
		{
			if ((*tab)[i][j] == info->obstacle)
				grid[i][j] = 0;
			else
				grid[i][j] = 1;
			j++;
		}
		i++;
	}
	return (grid);
}

void	solvetab(char ***tab, t_info *info)
{
	int	i;
	int	j;
	int	max;
	int	x;
	int	y;

	max = algorithme(creategrid(tab, info), info, &j, &i);
	y = i - max + 1;
	while (y <= i)
	{
		x = j - max + 1;
		while (x <= j)
		{
			(*tab)[y][x] = info->plein;
			x++;
		}
		y++;
	}
}
