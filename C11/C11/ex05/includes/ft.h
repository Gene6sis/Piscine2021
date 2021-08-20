/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:31:58 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/20 01:43:53 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

#include <unistd.h>

void		ft_putnbr(int nb);
void		ft_putchar(char c);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
int			addition(int a, int b);
int			soustraction(int a, int b);
int			multiplication(int a, int b);
int			division(int a, int b);
int			modulo(int a, int b);
void		operateur(int a, char op, int b);

#endif
