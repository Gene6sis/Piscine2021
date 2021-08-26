# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 14:46:05 by adben-mc          #+#    #+#              #
#    Updated: 2021/08/25 23:27:14 by oaarsse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFOL = srcs/

SRC			=	$(SRCFOL)algorithme.c \
				$(SRCFOL)ft_putstr.c \
				$(SRCFOL)ft_strlen.c \
				$(SRCFOL)parsing.c \
				$(SRCFOL)printtable.c \
				$(SRCFOL)ft_realloc.c \
				$(SRCFOL)isvalid.c \
				$(SRCFOL)ft_puterror.c \
				main.c

OBJS		=	${SRC:.c=.o}

INCLUDES	=	includes/

NAME		=	bsq

CFLAGS      =   -Wall -Wextra 

CC			=	gcc

RM			=	rm -f

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
