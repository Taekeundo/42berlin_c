# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 09:24:12 by tkwak             #+#    #+#              #
#    Updated: 2024/07/18 15:00:55 by tkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ COMMAND ]
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
CDEBUG		= -g -fsanitize=address -pedantic
RM			= rm -f

# [ FILE ]
NAME		= a.out
SRCS		= $(shell find -iname "*.cpp")
OBJS		= $(SRCS:.cpp=.o)

# [ COMPILE ]
%.o			: %.cpp
				$(CC) $(CLFAGS) $(CDEBUG) -c $< -o $@

$(NAME)		: $(OBJS)
				$(CC) $(CFLAGS) $(CDEBUG) -o $(NAME) $(OBJS)

# [ RULE ]
all			: $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		: clean
				$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
