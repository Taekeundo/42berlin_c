# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 15:43:58 by tkwak             #+#    #+#              #
#    Updated: 2025/03/18 15:43:59 by tkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ COMMAND ]
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
CDEBUG		= -fsanitize=address -g -pedantic
RM			= rm -f

# [ FILE ]
NAME		= mutantStack
SRCS		= $(shell find -iname "*.cpp")
OBJS		= $(SRCS:.cpp=.o)

# [ COMPILE ]
%.o			: %.cpp
				$(CC) $(CFLAGS) $(CDEBUG) -o $@ -c $<

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
