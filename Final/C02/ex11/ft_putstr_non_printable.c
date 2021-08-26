/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 01:38:11 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/07 14:47:35 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_checkhex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar((hex[c / 16]));
	ft_putchar((hex[c % 16]));
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			write(1, "\\", 1);
			ft_checkhex(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
