/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:57:00 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/19 18:17:22 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	unsigned int	i;
	unsigned int	compt;

	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			compt++;
		i++;
	}
	return (compt);
}
