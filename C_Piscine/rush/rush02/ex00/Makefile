NAME := rush-02
SRC := main.c
CC := cc
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

re: fclean all
