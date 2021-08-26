/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:42:58 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/25 22:00:08 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

char	**fill_tab(t_info *info, char *content, int k)
{
	char		**tab;
	int			i;
	int			j;

	tab = malloc(sizeof(*tab) * (info->row + 1));
	if (!tab)
		return (NULL);
	tab[info->row] = 0;
	i = -1;
	while (++i < info->row)
	{
		j = 0;
		tab[i] = malloc(sizeof(*tab[i]) * (info->col + 1));
		if (!tab[i])
			return (NULL);
		while (j < info->col)
			tab[i][j++] = content[k++];
		tab[i][j] = '\0';
		k++;
	}
	return (tab);
}

int	init_grid(char *content, t_info *info, char ***tab)
{
	int		i;
	int		k;

	i = 0;
	info->col = 0;
	while (content[i] != '\n')
		i++;
	k = i;
	while (content[++k] != '\n' && content[k])
		info->col++;
	if (!check_info(info))
		return (0);
	if (!is_map_valid(content, info))
		return (0);
	*tab = fill_tab(info, content, i + 1);
	if (!*tab)
		return (0);
	return (1);
}

int	parse_info(t_info *info, char *table)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	while (table[i] != '\n' && table[i])
		i++;
	if (i < 4)
		return (0);
	info->plein = table[i - 1];
	info->obstacle = table[i - 2];
	info->vide = table[i - 3];
	nbr = 0;
	j = -1;
	while (++j < (i - 3))
	{
		if (table[j] >= '0' && table[j] <= '9')
			nbr = (nbr * 10) + ((int)table[j] - '0');
		else
			return (0);
	}
	info->row = nbr;
	return (1);
}

char	*parse_file(int fd, t_info *info)
{
	char			*table;
	char			buff[50];
	int				i;
	unsigned long	position;
	int				size;

	table = malloc(sizeof(char));
	table[0] = '\0';
	size = read(fd, buff, 50);
	position = 0;
	while (size > 0)
	{
		table = ft_realloc(table, size);
		if (!table)
			return (NULL);
		i = 0;
		while (i < size)
			table[position++] = buff[i++];
		size = read(fd, buff, 50);
	}
	if (table[0] == '\0')
		return (NULL);
	if (!parse_info(info, table))
		return (NULL);
	return (table);
}

int	parse(char *file, char ***tab, t_info *info)
{
	int		fd;
	char	*content;

	if (file == 0)
		fd = 0;
	else
		fd = open(file, O_RDONLY);
	content = parse_file(fd, info);
	if (!content)
		return (0);
	if (!init_grid(content, info, tab))
		return (0);
	return (1);
}
