# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 13:43:59 by tkwak             #+#    #+#              #
#    Updated: 2024/06/25 13:44:00 by tkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ COMMAND ]
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
CDEBUG		= -g -fsanitize=address -pedantic
RM			= rm -f

# [ FILE ]
NAME		= zombie
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
