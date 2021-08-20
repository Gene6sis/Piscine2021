/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:16:29 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/10 19:59:11 by adben-mc         ###   ########.fr       */
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

#include <stdio.h>
int main()
{
	printf("%d\n", ft_is_prime(79));
	printf("%d\n", ft_is_prime(53));
	printf("%d\n", ft_is_prime(37));
	printf("%d\n", ft_is_prime(8));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(-10));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(0));
}
