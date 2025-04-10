# Compiler
CC			=	cc

# Compilation flags (compiling options)
CFLAGS		=	-Wall -Wextra -Werror -g -pthread -O3 -fsanitize=address
## To check the memory leaks, choose one of the three options below
##	1. "-fsanitize=thread"		// to the "CFLAGS"
##	2. "-fsanitize=address"		// to the "CFLAGS"
##	3. valgrind --fair-sched=yes --leak-check=full --show-leak-kinds=all -s ./philo 5 800 200 200 5

# Command for file removal
RM			=	rm -rf

# Name of the executable file
NAME		=	philo

# Directory, where header files are located.
INCLUDES	=	./includes/

# Directory, where source files are located.
DIRECTORY	=	./srcs/

# Sub-directory, are containing utility functions.
UTILS		=	utils/

# List of all source files needed for the build.
SRCS		=	main.c						\
				dining.c					\
				$(UTILS)atomic_mutex.c		\
				$(UTILS)handle_safely.c		\
				$(UTILS)initializer.c		\
				$(UTILS)scenario_checker.c	\
				$(UTILS)utils_1.c			\
				$(UTILS)utils_2.c

# List of full paths to source files by combining D & S.
SRC			=	$(addprefix $(DIRECTORY), $(SRCS))

# List of object files (individual compiled source files)
OBJ			=	$(SRC:.c=.o)

# Compilation Rules
%.o			:	%.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

# Build Rules
$(NAME)		:	$(OBJ)
				$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJ)

# Main Build Rule
all			:	$(NAME)

# Cleanup Rules
clean		:
				$(RM) $(OBJ)

fclean		: clean
				$(RM) $(NAME)

re			: fclean all

# .PHONY Set-up
.PHONY		: all clean fclean re
## PHONY: '가짜' 의미
## make 명령이 실행되는 디렉토리에 Makefile의 target과
## 같은 이름의 파일이 존재할 경우에 충돌이 발생.
## (ex) 'clean'이라는 파일이 존재할 경우
##		 PHONY에서 이미 clean을 선언해주었기에 충돌을 피할 수 있다.
