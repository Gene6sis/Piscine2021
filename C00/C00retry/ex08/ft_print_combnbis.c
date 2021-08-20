/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:24:16 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/11 15:03:25 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int mylast(int nb)
{
	int i;
	int	j;
	int last;
	
	i = 0;
	j = 10 - nb;
	last = 0;
	while(i < nb)
	{
		last = last * 10 + j;
		j++;
		i++;
	}
	return (last);
}

void ft_putnbr(int *tab, int size, int last)
{
	int i;
	int r;
	int nb;

	nb = 0;
	i = 10 - size;
	while (i < 10)
	{
		r = (int)tab[i] + '0';
		write(1, &r, 1);
		nb = nb * 10 + tab[i];
		i++;
	}
	if (nb != last)
		write(1, ", ", 2);
}

void	fild(int *tab, int n, int size)
{
	int	i;
	int res;

	i = 0;
	while (i < 10)
		tab[i++] = 0;
	i = 0;
	while (i < size)
	{
		tab[9 - i] = n % 10;
		n /= 10;
		i++;
	}
}

void	ft_test(int *tab, int size, int last)
{
	int i;

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
	int tab[10];
	int i;
	int power;
	int	last;

	i = -1;
	power = 1;
	last = mylast(n);
	while (++i < n)
	{
		power *= 10;
	}
	i = -1;
	while (++i <= last)
	{
		fild(tab, i, n);
		ft_test(tab, n, last);
	}
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	//printf("%d\n", mylast(atoi(argv[1])));
	ft_print_combn(atoi(argv[1]));
}
