# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 22:05:26 by adben-mc          #+#    #+#              #
#    Updated: 2021/08/17 23:50:08 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFOLD		=	./srcs/
HEADFOLD	=	./includes/
SRCS		=	${SRCFOLD}ft_putchar.c	\
				${SRCFOLD}ft_putstr.c	\
				${SRCFOLD}ft_strcmp.c	\
				${SRCFOLD}ft_strlen.c	\
				${SRCFOLD}ft_swap.c
HEADER		=	${HEADFOLD}ft.h
OBJS		=	${SRCS:.c=.o}
NAME		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADFOLD}
${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}
all: ${NAME}
clean: 
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re:	fclean all
.PHONY: all clean fclean re
