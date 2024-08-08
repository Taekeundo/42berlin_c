/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:37:40 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 03:16:24 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_string.h"

#define BUFFER_SIZE 1023

void	throw_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

// Appends two strings into one buffer
char	*ft_strapp(char *s1, char *s2)
{
	char	*res;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	free(s1);
	return (res);
}

ssize_t	ft_read(int fd, char **out)
{
	ssize_t	i;
	ssize_t	r;
	char	*buff;

	i = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	r = read(fd, buff, BUFFER_SIZE);
	if (r > 0)
	{
		buff[r] = 0;
		*out = ft_strapp(*out, buff);
		if (!out)
			i = -1;
		else
			i = ft_read(fd, out);
	}
	free(buff);
	if (i == -1)
		return (-1);
	return (r + i);
}

char	*ft_read_from_file(const char *filepath)
{
	int		fd;
	ssize_t	fsize;
	char	*stream;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (NULL);
	stream = malloc(BUFFER_SIZE + 1);
	if (!stream)
	{
		close(fd);
		return (NULL);
	}
	stream[0] = '\0';
	fsize = ft_read(fd, &stream);
	if (fsize == -1)
	{
		free(stream);
		return (NULL);
	}
	if (close(fd))
		return (NULL);
	return (stream);
}
