/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:58:09 by oaarsse           #+#    #+#             */
/*   Updated: 2021/08/25 22:01:05 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

void	printtable(char **tab, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row)
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}
