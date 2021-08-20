/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:10:03 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/17 03:15:15 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				checkbase(char *str);
int				checkintbase(char c, char *base);
long long int	ft_atoi_base(char *str, char *base);
int				ft_strlen(char *str);

char	*ft_itoabasefinal(char *base, int negative, long int nb, int size)
{
	int		size_base;
	int		i;
	char	*strfinal;

	strfinal = malloc(sizeof(char) * (size + 1));
	if (!strfinal)
		return (0);
	strfinal[size] = '\0';
	i = size - 1;
	size_base = ft_strlen(base);
	while (i > 0)
	{
		strfinal[i] = base[nb % size_base];
		nb /= size_base;
		i--;
	}
	if (negative == -1)
		strfinal[0] = '-';
	else
		strfinal[0] = base[nb];
	return (strfinal);
}

char	*ft_itoabase(int nb, char *base)
{
	int			size;
	int			size_base;
	int			temp;
	long int	nbr;
	int			negative;

	negative = 1;
	size = 1;
	nbr = nb;
	if (nbr < 0)
	{
		negative *= -1;
		size++;
		nbr = -nbr;
	}
	size_base = ft_strlen(base);
	temp = size_base;
	while (temp <= nbr)
	{
		temp *= size_base;
		size++;
	}
	return (ft_itoabasefinal(base, negative, nbr, size));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*strfinal;

	if (!nbr || !base_from || !base_to || !checkbase(base_to)
		|| !checkbase(base_from))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	if (nb == 0)
	{
		strfinal = malloc(sizeof(char) * 2);
		if (!strfinal)
			return (NULL);
		strfinal[0] = base_to[0];
		strfinal[1] = '\0';
	}
	else
		strfinal = ft_itoabase(nb, base_to);
	return (strfinal);
}
