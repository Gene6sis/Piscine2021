/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:43:35 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/22 22:30:20 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_translate(char *str, char *nb);
char 	*create_str(char *file);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char	c);
int		ft_recursive_power(int nb, int power);
void	ft_affiche(char *nb, char *dico);
char    *ft_itoa(int nb);
int		ft_lennb(int nb);
char	*format(int a, int b);

#endif
