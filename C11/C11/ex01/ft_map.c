/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:51:33 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/19 15:53:43 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
int	*ft_map(int *tab, int length, int(*f)(int))
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
	return (tab);
}