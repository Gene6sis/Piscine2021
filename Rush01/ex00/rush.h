/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:22:55 by adben-mc          #+#    #+#             */
/*   Updated: 2021/08/15 19:23:40 by adben-mc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		is_ok_size_argc(char *str);
int		is_correct_format(char *str, int num);
int		*num_str_to_int(char *str, int num);
int		**ft_create_board(int num);
void	ft_print_board(int **board, int num);
void	ft_free_board(int **board, int num);
int		ft_is_in_col(int value, int **board, int x, int num);
int		ft_is_col_valid_down(int **board, int *condition, int col, int num);
int		ft_is_col_valid_up(int **board, int *condition, int col, int num);
int		ft_checkcol(int **board, int *cond, int y, int num);
int		ft_is_in_row(int value, int **board, int y, int num);
int		ft_is_row_valid_right(int **board, int *condition, int row, int num);
int		ft_is_row_valid_left(int **board, int *condition, int row, int num);
int		ft_checkrow(int **board, int *cond, int x, int num);

#endif
