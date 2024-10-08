NAME =	libftprintf.a
SRC =	ft_printf.c
OBJ =	$(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

all:$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re