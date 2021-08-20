/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:37:30 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/20 01:47:14 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	func(int nb1, int nb2, int (*fu)(int, int))
{
	ft_putnbr(fu(nb1, nb2));
	write(1, "\n", 1);
}

void	operateur(int a, char op, int b)
{
	if (op == '-')
		func(a, b, &soustraction);
	else if (op == '+')
		func(a, b, &addition);
	else if (op == '*')
		func(a, b, &multiplication);
	else if (op == '/')
	{
		if (b != 0)
			func(a, b, &division);
		else
			write(1, "Stop : division by zero\n", 24);
	}
	else if (op == '%')
	{
		if (b != 0)
			func(a, b, &modulo);	
		else
			write(1, "Stop : modulo by zero\n", 22);
	}
	else
		write(1, "0\n", 2);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putnbr(0);
		write(1, "\n", 1);
	}
	else
		operateur(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3]));
	return (0);
}
