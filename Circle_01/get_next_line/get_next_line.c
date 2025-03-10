/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:32:11 by tkwak             #+#    #+#             */
/*   Updated: 2023/09/11 19:35:29 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	[F]
	[ Definition ]
	Read the file from the Param(1):"fd",
	store all result into the Param(2):"static_buffer".

	[ Background ]
	1. [f] read (int fd, void *buf, size_t nbytes)
		= Read from the file, Param(1):"fd"
		= Save result to the Param(2):"buf"
		= As many as Param(3):"nbytes".

	2. Why using 'tmp_buffer'?
		= Efficiency
			Reading the entire file file at once,
			can be indefficient time-consuming, expecially for large files.
			by using 'tmp_buffer', read the file in smaller chunks.
		
		= Line by line reading
			The project's goal is to read one line at one time,
			until encountering a '\n'.

	[ Logic ]
	1. Allocate memory(tmp_buffer) to read for only one line.
	2. The while loop will run as long as there is a '\n' in the file.
	3. read from 'fd' & store it to 'tmp_buffer' as many as 'BUFFER_SIZE'.
	4. If [f]read fails -> size == -1
		No more need to use "static_buffer" & "tmp_buffer". (free)
	5. else [f]read success
		Put the '\0' to ensure the 'tmp_buffer' is properly terminated C string.
		Append the 'tmp_buffer' to 'static_buffer'.
*/
char	*read_and_cpy_file(int fd, char *static_buffer)
{
	char	*tmp_buffer;
	int		size;

	tmp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp_buffer == NULL)
		return (NULL);
	size = 1;
	while ((ft_strchr(static_buffer, '\n') == 0) && size)
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

/*	[F]
	[ Goal ]
	Extracts the first line from the param:static_buffer.

	[ Logic ]
	1. Iterates throught the buffer to find the first newline.
	2. Allcates memory to store the extracted line, including the neline if present.
	3. Copies the characters up to the newline into a new string and returns it.

	[ Return ]
	A string containing the first line, which includes the newline, if exists.
*/
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

/*	[F]
	[ Goal ]
	Moves the static_buffer's pointer forward.

	[ Memo ]
	It frees the old buffer and returns a pointer to the new part of the buffer (After the newline).
*/
char	*move_to_next_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\0')
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

/*	[F]
	[ Definition ]
	Read a file through the Param:"fd"(= File descriptor),
	Until encountering the newline (= '\n').
	= Read one line from the file.

	[ Return ]
	One line, that is read from the file.
	If the end of the file is reached or an error occurs, return (NULL).

	[ Variable ]
	static char *static_buffer;

	  .	pointer -----> -------------
					   |    4th    |	ddddd\n
					   -------------
					   |    3rd    |	ccccc\n
					   -------------
					   |    2nd    |	bbbbb\n
					   -------------
					   |    1st    |	aaaaa\n
					   -------------

	[ Logic ]
	1. If (BUFFER_SIZE <= 0)
		= Check if the buffer size is valid.

	2. static_buffer = read_and_cpy_file(fd, static_buffer);
		= Read the file from the Param:"fd" and store all result into the [v]static_buffer.
		= Data type: static	 // store one line by one line into the 'static_buffer'.
		
		2-1. if (static_buffer == NULL)
			= Error handling, when there is nothing more to read, return (NULL).

	3. line = copy_one_line(static_buffer);
		= Copy one line from the [v]static_buffer.
	
	4. static_buffer = move_to_next_line(static_buffer);
		= Move the pointer of the [v]static buffer to the start of the next line.

	5. return (line);
		= Return the line that was read.
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buffer;

	if (BUFFER_SIZE <= 0)
		return (0);
	static_buffer = read_and_cpy_file(fd, static_buffer);
	if (static_buffer == NULL)
		return (NULL);
	line = cpy_one_line_from_buffer(static_buffer);
	static_buffer = move_to_next_line(static_buffer);
	return (line);
}

/* [ Testing ] */
#include <fcntl.h>

int main(void)
{
	int fd;
	char *res;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((res = get_next_line(fd)) != NULL)
	{
		printf("Result: %s", res);
		free(res);
	}
	close(fd);
	return (0);
}