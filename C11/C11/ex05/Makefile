# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 22:05:26 by adben-mc          #+#    #+#              #
#    Updated: 2021/08/20 01:45:06 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFOLD		=	./srcs/
HEADFOLD	=	./includes/
SRCS		=	${SRCFOLD}ft_atoi.c		\
				${SRCFOLD}do-op.c		\
				${SRCFOLD}operation.c	\
				${SRCFOLD}ft_putnbr.c
HEADER		=	${HEADFOLD}ft.h
OBJS		=	${SRCS:.c=.o}
NAME		=	do-op
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}
${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
all: ${NAME}
clean: 
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re:	fclean all
.PHONY: all clean fclean re
