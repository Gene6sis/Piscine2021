/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:40:58 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/10 17:46:22 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power != 0)
		return (nb * ft_recursive_power(nb, power - 1));
	return (1);	
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_recursive_power(53, 5));
}
