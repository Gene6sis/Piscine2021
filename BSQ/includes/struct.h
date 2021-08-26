/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:49:06 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/25 16:53:33 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_struct
{
	char			c;
	struct s_struct	*previous;
	struct s_struct	*next;
}	t_bo;

typedef struct s_info
{
	char	vide;
	char	plein;
	char	obstacle;
	int		col;
	int		row;
}	t_info;

#endif
