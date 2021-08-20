/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:43 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/19 23:27:21 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	unsigned int	i;
	unsigned int	compt_croiss;
	unsigned int	compt_decroiss;

	i = 1;
	compt_decroiss = 1;
	compt_croiss = 1;
	if (length <= 1)
		return (1);
	while (i < length)
	{
		if ((*f)(tab[i], tab[i - 1]) > 0)
			compt_decroiss++;
		if ((*f)(tab[i], tab[i - 1]) < 0)
			compt_croiss++;
		if ((*f)(tab[i], tab[i - 1]) == 0)
		{
			compt_croiss++;
			compt_decroiss++;
		}
		i++;
	}
	if (compt_croiss == length || compt_decroiss == length)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int ft_cmp(int a, int b)
{
	if (a < b)
		return (-1);
	if (a == b)
		return (0);
	if (a > b)
		return (1);
	return (1);
}

int main()
{
	int (*f)(int, int);
	f = &ft_cmp;
	int tab[100] = {3,2,3,4,5,6,7,8,9};
	printf("return : %d\n", ft_is_sort(tab, 9, f));
}*/
