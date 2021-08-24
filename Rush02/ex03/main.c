/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:14:59 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/22 20:53:18 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int main(int argc, char **argv)
{
	int error;
	char *dico;
	char *nb;


	error = 1;
	if (argc == 2 || argc == 3)
	{
		if(argc == 2)
			dico = create_str("numbers.dict");
		else if (argc == 3)
			dico = create_str(argv[2]);
		//nb = clean_numbers(argv[1]);
		//error = print_number(nb, dico);
		//printf("%s\n", ft_translate(dico, argv[1]));
		ft_affiche(argv[1], dico);
	}
	else
	{
		error = 1;
		write(1, "Error\n", 6);
	}
	return (error);
}
