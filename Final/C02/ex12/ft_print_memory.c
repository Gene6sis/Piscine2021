/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:37:57 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/07 14:47:56 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_n(char *c, int size)
{
	int	i;

	i = -1;
	while (i++ < size - 1)
	{
		if (c[i] >= ' ' && c[i] <= '~')
			write(1, &c[i], 1);
		else
			write(1, ".", 1);
	}
}

char	*ft_base_hex(unsigned long long nbr, char *conv, int size, int pos)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr / 16 > 0 && pos < size)
		ft_base_hex(nbr / 16, conv, size, pos + 1);
	conv[size - pos] = base[nbr % 16];
	return (conv);
}

void	ft_print_addr(void *addr)
{
	int		i;
	char	adresse[16];

	i = -1;
	while (i++ < 16)
		adresse[i] = '0';
	ft_base_hex((unsigned long long)addr, adresse, 16, 0);
	i = -1;
	ft_print_n(adresse, 16);
}

void	afficher_ligne(void *addr, int size)
{
	int		i;
	char	conv[30];

	ft_print_addr(addr);
	ft_print_n(": ", 2);
	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_print_n(ft_base_hex(*(char *)addr, conv, 1, 0), 2);
		else
			write(1, " ", 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
		addr++;
	}
	addr -= 16;
	i = 0;
	ft_print_n((char *)addr, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;

	i = size;
	while (i > 16)
	{
		afficher_ligne(addr, 16);
		i -= 16;
		addr += 16;
	}
	afficher_ligne(addr, size % 16);
	addr -= size - (size % 16);
	return (addr);
}
