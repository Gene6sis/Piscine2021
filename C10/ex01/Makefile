CC=gcc
NAME=ft_cat
SRC=ft_cat.c
OBJ=$(SRC:.c=.o)
FLAGS=-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

