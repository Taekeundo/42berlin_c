/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:31:25 by tkwak             #+#    #+#             */
/*   Updated: 2024/08/08 11:25:09 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h> 
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*read_and_cpy_file(int fd, char *static_buffer);
char	*cpy_one_line_from_buffer(char *static_buffer);
char	*move_to_next_line(char *static_buffer);
char	*get_next_line(int fd);
char	*ft_strjoin(char *l_str, char *r_str);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);

#endif
