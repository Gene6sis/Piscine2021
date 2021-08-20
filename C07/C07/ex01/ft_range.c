/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:48:57 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/13 22:45:43 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *tab;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(min) * (max - min));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < (max-min))
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

#include <stdio.h>
int    main()
{
    int *tab = ft_range(5, 8);
    int i = 0;
    while(i < 3)
    {
        printf("%i\n", tab[i]);
        i++;
    }
}
