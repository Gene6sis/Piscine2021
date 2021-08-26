/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:41:42 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/25 22:45:08 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

int	is_map_valid(char *map, t_info *info)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (map[num] != '\0' && map[num] != '\n')
		num++;
	num++;
	while (i++ < info->row)
	{
		j = 0;
		while (j++ < info->col)
		{
			if ((map[num] != info->vide && map[num] != info->obstacle)
				|| map[num] < ' ' || map[num] > '~')
				return (0);
			num++;
		}
		if (map[num++] != '\n')
			return (0);
	}
	if (map[num] != '\0')
		return (0);
	return (1);
}

int	check_info(t_info *info)
{
	if ((info->vide < ' ' && info->vide > '~')
		|| (info->plein < ' ' && info->plein < '~')
		|| (info->obstacle < ' ' && info->obstacle < '~'))
		return (0);
	if (info->vide == info->plein || info->vide == info->obstacle
		|| info->plein == info->obstacle)
		return (0);
	if (info->row == 0 || info->col == 0)
		return (0);
	return (1);
}
