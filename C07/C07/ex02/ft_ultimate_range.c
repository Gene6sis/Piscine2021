/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:03:34 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/13 01:48:06 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int    ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int    *str;

    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    str = malloc(sizeof(int) * (max - min));
	if (str == NULL)
		return (-1);
	i = 0;
    while (min < max)
    {
        str[i] = min;
        min++;
        i++;
    }
    *range = str;
    return (i);
}

#include <stdio.h>
int    main()
{
    int *tab;
    ft_ultimate_range(&tab, -2, 8);
    int i = 0;
    while(i < 10)
    {
        printf("%d\n", (*tab + i));
        i++;
    }
}

// Fonctionne pas DAMIEN HELP ME
