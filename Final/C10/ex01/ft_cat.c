/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:13:33 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/26 17:32:48 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int	output_port(int port)
{
	int		nb_read;
	char	buf[16];

	nb_read = read(port, buf, 16);
	while ((nb_read))
	{
		if (nb_read == -1)
			return (0);
		write(1, buf, nb_read);
		nb_read = read(port, buf, 16);
	}
	return (1);
}

int	print_file(char *path)
{
	int		file;

	file = open(path, O_RDONLY);
	if (file <= 0 || !output_port(file))
		return (0);
	else
		close(file);
	return (1);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	print_err(char *binpath, char *filepath)
{
	ft_puterr(basename(binpath));
	ft_puterr(": ");
	ft_puterr(filepath);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		output_port(STDIN_FILENO);
	else
	{
		while (++i < argc)
		{
			if (argv[i][0] == '-')
				output_port(STDIN_FILENO);
			else if (!print_file(argv[i]))
				print_err(argv[0], argv[i]);
		}
	}
	return (0);
}
