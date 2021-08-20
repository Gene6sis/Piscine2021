/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 01:53:46 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/09 15:58:25 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	sizefind;
	int	i;
	int	j;

	if(to_find[0] == '\n')
		return(str);	
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (!to_find[j + 1])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

#include <string.h>
#include <stdio.h>
int main()
{
	char *str = "coucou";
	char *tofind = "ou";

	printf("%s\n", ft_strstr(str, tofind));
	printf("%s\n", strstr(str, tofind));

}
