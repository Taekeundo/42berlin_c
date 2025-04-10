# DEFINE
NAME			=	so_long
INCLUDE			=	-I./include -I $(MLX_DIR)/include/MLX42

# EXECUTABLE
CC			=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
RM			=	rm -f
AR			=	ar rcs

# DIRECTORY
SRCS_DIR		=	./src/
OBJS_DIR		=	./obj/

# SOURCE
SRCS			=	$(shell find $(SRCS_DIR) -name "*.c")
OBJS			=	$(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))

# LIBRARY (.a file)
GETNL			=	lib/get_next_line/get_next_line.a
LIBFT			=	lib/libft/libft.a
FT_PRINTF		=	lib/ft_printf/ft_printf.a

# ALL LIBRARY (All .a file)
ALL			=	$(GETNL) $(LIBFT) $(FT_PRINTF)

# ADDTINAL DIRECTORY
GETNL_DIR		=	./lib/get_next_line

# MLX
MLX_DIR			=	./lib/MLX42
MLX			=	./lib/MLX42/build/libmlx42.a
MFLAGS 			= 	-L/opt/homebrew/opt/glfw/lib -lglfw -L./lib/MLX42/build -lmlx42 -Iinclude -ldl -pthread -lm

# LEAK CHECK
VALGRIND		=	@valgrind --leak-check=full

# MAIN COMMAND
all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(GETNL_DIR)
			@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
			$(CC) -g $(CFLAGS) $(MFLAGS) $(OBJS) $(ALL) $(MLX) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			$(CC) -g $(INCLUDE) -c $< -o $@

clean:
			$(RM) -rf $(OBJS_DIR)
			$(RM) -rf $(MLX_DIR)/build
			@make clean -C $(GETNL_DIR)

fclean:		clean
			$(RM) -f $(NAME)
			@$(RM) -f $(ALL)

re:			fclean all
		
.PHONY:		all clean fclean re
