# DEFINE
NAME		=	get_next_line.a
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

# LIBRARY (.a file)
FT_PRINTF	=	../ft_printf/ft_printf.a

# MAIN COMMAND
all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C ../ft_printf
			cp $(FT_PRINTF) $(NAME)
			@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
			
clean:
			$(RM) -rf $(OBJS_DIR)
			@make clean -C ../ft_printf

fclean:		clean
			$(RM) -f $(NAME)
			@$(RM) -f $(FT_PRINTF)

re:			fclean all

.PHONY:		all clean fclean re
