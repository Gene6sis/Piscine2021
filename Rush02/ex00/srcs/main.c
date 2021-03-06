/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:14:59 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/21 17:26:40 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	int error;
	char ***dico;
	char *nb;

	error = 1;
	if (argc == 2 || argc == 3)
	{
		if(argc == 2)
			dico = parsingdico("numbers.dict");
		else if (argc == 3)
			dico = parsingdico(argv[2]);
		nb = clean_numbers(argv[1]);
		error = print_number(nb, dico);
	}
	else
	{
		error = 1;
		write(1, "Error\n", 6);
	}
	return (error);
}
