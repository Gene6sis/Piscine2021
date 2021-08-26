/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:59:21 by oaarsse           #+#    #+#             */
/*   Updated: 2021/08/25 19:39:47 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

char	*ft_realloc(char *str, int to_add)
{
	char			*new;
	unsigned long	len;
	int				i;

	len = ft_strlen(str);
	new = malloc(sizeof(*str) * ((len + to_add) + 1));
	if (!new)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[(len + to_add)] = '\0';
	free(str);
	return (new);
}
