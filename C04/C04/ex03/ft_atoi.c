/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:37:27 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/21 22:44:14 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int res;
	int sign;
	int i;

	res = 0;
	i = 0;
	sign = 1;
	while(str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == ' ')
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] <= '9' && str[i] >= '0')
	{
		res *= 10;
		res += (int)str[i++] - '0';
	}
	return (sign * res);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	printf("%d\n", ft_atoi(argv[1]));
}
