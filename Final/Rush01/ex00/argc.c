/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:32:31 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/15 22:46:45 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_ok_size_argc(char *str)
{
	if ((ft_strlen(str) + 1) * 10 % 80 == 0 && ft_strlen(str) < 72
		&& ft_strlen(str) >= 31)
		return (1);
	return (0);
}

int	is_correct_format(char *str, int num)
{
	int	i;

	i = 0;
	if (!is_ok_size_argc(str))
		return (0);
	while (str[i])
	{
		if ((str[i] < '1' || str[i] > (num + '0')) && i % 2 == 0)
		{
			return (0);
		}
		if (i % 2 == 1 && str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	*num_str_to_int(char *str, int num)
{
	int	i;
	int	j;
	int	*cond;

	cond = malloc(sizeof(int) * (num * num));
	if (!cond)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(str))
	{
		cond[j] = (int)str[i] - '0';
		j++;
		i += 2;
	}
	return (cond);
}
