NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -g
PUSH_SWAP_ARCHIVE = ../push_swap/push_swap.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c 
	$(CC) -c $(CFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(PUSH_SWAP_ARCHIVE) 
	$(CC) $^ -o $(NAME)
	cp $(NAME) ../push_swap 

$(PUSH_SWAP_ARCHIVE) :
	cd ../push_swap && make

clean :
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)
	cd ../push_swap && rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
