/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 02:27:14 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/09 15:07:56 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len_src;
	unsigned int len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i = 0;
	if (len_dest >= size)
		return (len_src + size);
	while (src[i] && ((len_dest + i) < (size - 1)))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}

#include <stdio.h>
#include <string.h>

int main(void) {

	char dst[100] = "1234";
	char src[100] = "ABCD";
	char dst1[100] = "1234";
	char src1[100] = "ABCD";
	int size = 20;

	printf("// Retourne %lu\n", strlcat(dst, src, size));
	printf("// dst = %s\n", dst);
	printf("// src = %s\n", src);
	printf("// Retourne %u\n", ft_strlcat(dst1, src1, size));
	printf("// dst = %s\n", dst1);
	printf("// src = %s\n", src1);
	return 0;
}
