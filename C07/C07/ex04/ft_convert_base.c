/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:10:03 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/16 16:23:33 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int				checkbase(char *str);
int				checkintbase(char c, char *base);
int				ft_sign(char *str);
long long int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_size(long long int nb, char *base)
{
	int	size;
	int	len;

	if (nb == 0)
		return (1);
	len = ft_strlen(base);
	size = 0;
	while (nb != 0)
	{
		nb /= len;
		size++;
	}
	return (size);
}

void	reverse(char *result)
{
	int		i;
	int		j;
	char	c;

	j = ft_strlen(result) - 1;
	i = 0;
	while (i < j)
	{
		c = result[i];
		result[i] = result[j];
		result[j] = c;
		i++;
		j--;
	}
}

void	convert(char *result, long long int nb, char *base, int size)
{
	int	i;
	int	sign;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	result[i] = base[nb % ft_strlen(base)];
	while (i < (size))
	{
		result[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	if (sign == 1)
		result[i] = '-';
	i++;
	result[i] = '\0';
	reverse(result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long int	nb;
	int				size;
	char			*result;
	int				sign;

	nb = ft_atoi_base(nbr, base_from);
	printf("conversion : %llu\n", nb);
	sign = (nb < 0);
	size = ft_size(nb, base_to);
	result = malloc(sizeof(char) * (size + 1 + sign));
	if (!result)
		return (0);
	convert(result, nb, base_to, size);
	return (result);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
}

