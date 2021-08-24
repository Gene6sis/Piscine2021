/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:28:46 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/22 22:29:37 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int    ft_lennb(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		count++;
	else if (nb < 10)
	{
		count++;
		nb = 0;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char    *ft_itoa(int nb)
{
	char            *str;
	int                i;
	int                lennb;
	unsigned int    nbr;

	lennb = ft_lennb(nb);
	str = malloc(sizeof(char) * (lennb + 1));
	nbr = nb;
	i = lennb;
	if (nbr < 10)
	{
		str[--i] = nbr + '0';
		nbr = 0;
	}
	while (nbr != 0)
	{
		str[--i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[lennb] = '\0';
	return (str);
}

char	*format(int a, int b)
{
	int nb;
	char *format;

	nb = ft_recursive_power(a, b);
	format = ft_itoa(nb);
	return (format);
}
