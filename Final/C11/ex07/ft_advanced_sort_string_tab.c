/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:44:10 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/23 00:05:12 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(tab);
	i = 1;
	while (i <= len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (((*cmp)(tab[j], tab[j + 1])) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int main(int argc, char **argv)
{
	int	(*cmp)(char *, char *);
	cmp = &ft_strcmp;
	ft_advanced_sort_string_tab(argv, cmp);
	for (int i = 0; argv[i]; i++)
		printf("%s\n", argv[i]);
}
*/
