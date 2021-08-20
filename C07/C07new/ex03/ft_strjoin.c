/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 01:42:38 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/16 15:14:55 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*concatenate(int size, char *sep, char **strs, char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[len++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != (size - 1))
			str[len++] = sep[j++];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	len = 0;
	while (i < size)
	{
		if (strs[i] == NULL)
			return (NULL);
		len += ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (size == 0)
		return (str);
	str = concatenate(size, sep, strs, str);
	return (str);
}
