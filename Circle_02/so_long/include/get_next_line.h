/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:21:47 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:21:49 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* library */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "libft.h"

/* define */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* struct : NOW IT USED BY FT_PRINTF */
/* typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list; */

/* main functions */
char	*get_next_line(int fd);
int		read_to_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, int fd_readed);
int		extract_stash(t_list *stash, char **line);
void	clean_stash(t_list **stash);

/* utils functions */
int		found_newline(t_list *stash);
// t_list	*ft_lstlast(t_list *stash); // printf
int		as_much_newline(t_list *stash, char **line);
void	free_stash(t_list *stash);
// size_t	ft_strlen(const char *str); // printf

# define CODE_OK 1
# define CODE_ERROR 0

#endif
