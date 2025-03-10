/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:02:39 by tkwak             #+#    #+#             */
/*   Updated: 2023/09/09 18:06:30 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_cpy_file(int fd, char *static_buffer)
{
	char	*tmp_buffer;
	int		size;

	tmp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(static_buffer, '\n') && size)
	{
		size = read(fd, tmp_buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(static_buffer);
			free(tmp_buffer);
			return (NULL);
		}
		tmp_buffer[size] = '\0';
		static_buffer = ft_strjoin(static_buffer, tmp_buffer);
	}
	free(tmp_buffer);
	return (static_buffer);
}

char	*cpy_one_line_from_buffer(char *static_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (static_buffer[i] == '\0')
		return (NULL);
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*move_to_next_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	nextline = malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (!nextline)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
		nextline[j++] = static_buffer[i++];
	nextline[j] = '\0';
	free(static_buffer);
	return (nextline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buffer[4000096];

	if (BUFFER_SIZE <= 0)
		return (0);
	static_buffer[fd] = read_and_cpy_file(fd, static_buffer[fd]);
	if (static_buffer[fd] == NULL)
		return (NULL);
	line = cpy_one_line_from_buffer(static_buffer[fd]);
	static_buffer[fd] = move_to_next_line(static_buffer[fd]);
	return (line);
}
