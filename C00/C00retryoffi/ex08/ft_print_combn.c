/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:27:46 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/11 23:35:24 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	last_nb(int nb)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	last = 0;
	while (i < nb)
	{
		last = last * 10 + (10 - nb + i);
		i++;
	}
	return (last);
}

void	ft_putnbr(char *tab, int size, int last)
{
	int	i;
	int	r;
	int	nb;

	nb = 0;
	i = 10 - size;
	while (i < 10)
	{
		r = tab[i];
		write(1, &r, 1);
		nb = nb * 10 + tab[i] - '0';
		i++;
	}
	if (nb != last)
		write(1, ", ", 2);
}

void	fill(char *tab, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
		tab[i++] = '0';
	i = 0;
	while (i < size)
	{
		tab[9 - i] = n % 10 + '0';
		n /= 10;
		i++;
	}
}

void	print_on_condition(char *tab, int size, int last)
{
	int	i;

	if (size > 1)
	{
		i = 10 - size;
		while (i < 9)
		{
			if (tab[i] >= tab[i + 1])
				return ;
			i++;
		}
	}
	ft_putnbr(tab, size, last);
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i;
	int		last;

	last = last_nb(n);
	i = -1;
	while (++i <= last)
	{
		fill(tab, i, n);
		print_on_condition(tab, n, last);
		if (n == 9 && i == 23456789)
			i = 123456788;
	}
}
