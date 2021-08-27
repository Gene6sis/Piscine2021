CC=gcc
NAME=ft_display_file
SRC=main.c
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
