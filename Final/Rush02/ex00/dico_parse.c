/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:56:46 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/22 19:30:38 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
char	**ft_split(char *str, char *charset);

char *create_str(char *file)
{
	char buff[1];
	int fd;
	int i;
	char *str;

	i = 0;
	fd = open(file, O_RDONLY);

	while (read(fd, buff, 1) > 0)
		i++;
	close(fd);
	str = malloc(sizeof(char) * (i + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (read(fd, buff, 1) > 0)
		str[i++] = buff[0];
	return str;
}
