/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:03:34 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/16 15:07:15 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*str;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	str = malloc(sizeof(int) * (max - min));
	if (str == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		str[i] = min;
		min++;
		i++;
	}
	*range = str;
	return (i);
}
