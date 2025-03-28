# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 15:01:24 by tkwak             #+#    #+#              #
#    Updated: 2025/03/28 15:01:27 by tkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ COMMAND ]
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
CDEBUG		= -fsanitize=address -g -pedantic
RM			= rm -f

# [ FILE ]
NAME		= Serializer
SRCS		= $(shell find . -name "*.cpp")
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
