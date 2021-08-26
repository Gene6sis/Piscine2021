/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:47:35 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/25 22:04:34 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "struct.h"
# include <stdio.h> //bimbamboom

/*
 *	Parsing fichier
*/

int		parse(char *file, char ***tab, t_info *info);
int		store_lines(int fd, char **tab);

/*
 * Check
*/

int		is_map_valid(char *map, t_info *info); //check info et map
int		check_info(t_info *info);
/*
 * Resolution
*/
void	solvetab(char ***tab, t_info *info);

/*
 * Affichage
*/

void	printtable(char **tab, t_info *info);
void	ft_puterror(char *str);

/*
 * Autre
*/

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_realloc(char *str, int to_add);
#endif
