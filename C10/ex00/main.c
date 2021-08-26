/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:13:15 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/26 16:59:47 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_read_file(int file)
{
	char	buffer[10];
	int		nb_read;

	nb_read = read(file, buffer, 10);
	while (nb_read)
	{
		write(1, buffer, nb_read);
		nb_read = read(file, buffer, 10);
	}
}

int	main(int argc, char **argv)
{
	int	file;

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	ft_read_file(file);
	close(file);
	return (0);
}
