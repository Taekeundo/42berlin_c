# DEFINE
NAME		=	libft.a
INCLUDE		=	-I../../include

# EXECUTION
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM		=	rm -f
AR		=	ar rcs

# DIRECTORY
SRCS_DIR	=	./src/
OBJS_DIR	=	./obj/

# SOURCE
SRCS			=	$(shell find $(SRCS_DIR) -name "*.c")
OBJS			=	$(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))

# MAIN COMMAND
all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
			$(RM) -rf $(OBJS_DIR)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
