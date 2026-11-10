NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c printf_helper_one.c printf_helper_two.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c  $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
