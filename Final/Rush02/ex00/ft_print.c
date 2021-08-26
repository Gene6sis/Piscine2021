/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:58:19 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/22 22:32:22 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void unite(char *tab, char *dico, char *nb, int i)
{
	if (nb[i] == '0')
		return ;
	tab[0] = nb[i];
	tab[1] = '\0';
	ft_putstr(ft_translate(dico, tab));
}

void centaine(char *tab, char *dico, char *nb, int i)
{
	if (nb[i] == '0')
		return ;
	tab[0] = nb[i];
	tab[1] = '\0';
	ft_putstr(ft_translate(dico, tab));
	tab[0] = '1';
	tab[1] = '0';
	tab[2] = '0';
	tab[3] = '\0';
	ft_putstr(ft_translate(dico, tab));
	if (!(nb[i + 1] == '0' && nb[i + 2] == '0'))
		ft_putstr("and");
}

void dizaine10(char *tab, char *dico, char *nb, int *i)
{
	tab[0] = nb[*i];
	tab[1] = nb[*i + 1];
	tab[2] = '\0';
	ft_putstr(ft_translate(dico, tab));
	i += 1;
}

void dizaine(char *tab, char *dico, char *nb, int i)
{
	if (nb[i] == '0')
		return ;
	tab[0] = nb[i];
	tab[1] = '0';
	tab[2] = '\0';
	ft_putstr(ft_translate(dico, tab));
}

void ft_affiche(char *nb, char *dico)
{
	int len;
	char tab[4];
	int i;

	i = 0;
	len = ft_strlen(nb);
	while (nb[i])
	{
		if (len % 3 == 0)//centaine
			centaine(tab, dico, nb, i);
		else if (len % 3 == 2)//dizaine
		{
			if (nb[i] == '1')
				dizaine10(tab, dico, nb, &i);
			else
				dizaine(tab, dico, nb, i);	
		}
		else if (len % 3 == 1)//unite
			unite(tab, dico, nb, i);
		if ((len % 3 == 1) && len > 1)
		ft_putstr(ft_translate(dico, format(10, len - 1)));
		len--;
		i++;
	}
}
