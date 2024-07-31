# [ COMMAND ]
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CDEBUG		=	-g -fsanitize=address
RM			=	rm -rf
AR			=	ar crs

# [ FILE ]
NAME		=	libft.a
SRCS		=	$(shell find -iname "*.c")
OBJS		=	$(SRCS:.c=.o)

# [ COMPILE ]
%.0			:	%.c libft.h
				$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

$(NAME)		:	$(OBJS)
				$(AR) $(NAME) $(OBJS)

# [ RULE ]
all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
