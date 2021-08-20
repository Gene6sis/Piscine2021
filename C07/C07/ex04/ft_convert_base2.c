/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:10:14 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/16 14:51:53 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkbase(char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 31 || str[i] >= 127 || str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkintbase(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_sign(char *str)
{
	unsigned int	i;
	int				sign;

	i = 0;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

long long int	ft_atoi_base(char *str, char *base)
{
	long long int	result;
	unsigned int	len;
	unsigned int	i;

	if (!checkbase(base))
		return (0);
	len = 0;
	while (base[len])
		len++;
	i = 0;
	result = 0;
	if (ft_sign(str) == -1)
		i++;
	while (str[i])
	{
		if (checkintbase(str[i], base) == -1)
			return (0);
		result = result * len + checkintbase(str[i], base);
		i++;
	}
	return (result * ft_sign(str));
}
