/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:56:27 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/10 20:05:23 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int nbr;
	unsigned int i;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	nbr = nb;
	while ((i*i) < nbr)
	{
		if ((nbr % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_find_next_prime(42));
	printf("%d\n", ft_find_next_prime(79));
	printf("%d\n", ft_find_next_prime(75));
	printf("%d\n", ft_find_next_prime(150));
	printf("%d\n", ft_find_next_prime(98));
	printf("%d\n", ft_find_next_prime(-12));
	printf("%d\n", ft_find_next_prime(11));
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(0));
}
