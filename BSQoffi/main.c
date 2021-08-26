/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:27:21 by oaarsse           #+#    #+#             */
/*   Updated: 2021/08/25 22:22:39 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

int	main(int argc, char **argv)
{
	int		grid;
	char	**tab;
	t_info	*info;

	tab = NULL;
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	grid = 1;
	while (grid < (argc) || ((argc == 1) && (grid == 1)))
	{
		if (!parse(argv[grid], &tab, info))
			ft_puterror("map error\n");
		else
		{
			solvetab(&tab, info);
			printtable(tab, info);
		}
		if (grid != argc - 1 && argc > 2)
			ft_putstr("\n");
		grid++;
	}
}
