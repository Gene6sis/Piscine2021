/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:03:16 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/12 20:28:12 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int size;
	int i;
	char *dest;

	size = 0;
	while (src[size])
		size++;
	dest = malloc(sizeof(*src) * size);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
int main()
{
	char *str = "coucou toi";

	printf("Source \nMot : %s\nadresse : %p\n", str, str);
	printf("\nReturn :\nMot : %s\nadresse : %p\n", ft_strdup(str), ft_strdup(str));
	printf("Si l'adresse des 2 est differentes c'est good sinon nop\n");
}
