/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:51:33 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/23 00:04:46 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * length);
	while (i < length)
	{
		res[i] = ((*f)(tab[i]));
		i++;
	}
	return (res);
}
