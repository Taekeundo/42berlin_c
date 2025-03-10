/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 04:05:31 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 21:32:30 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_split.h"
#include "ft_string.h"

char	*trim_spaces_prefix(char *str)
{
	size_t	l;
	size_t	i;
	size_t	j;
	int		spaces;
	char	*trim;

	if (!str)
		return (NULL);
	spaces = 0;
	l = ft_strlen(str);
	i = 0;
	while (i++ && str[i] == ' ')
		spaces++;
	j = l - spaces + 1;
	trim = malloc(j);
	if (!trim)
		return (NULL);
	j = 0;
	while (i < l)
		trim[j++] = str[i++];
	return (trim);
}

char	*trim_spaces_suffix(char *str)
{
	size_t	l;
	size_t	i;
	size_t	j;
	int		spaces;
	char	*trim;

	if (!str)
		return (NULL);
	spaces = 0;
	l = ft_strlen(str);
	i = l;
	while (i-- && str[i] == ' ')
		spaces++;
	j = l - spaces + 1;
	trim = malloc(j);
	if (!trim)
		return (NULL);
	while (j--)
	{
		trim[j] = str[i];
		i--;
	}
	return (trim);
}

char	**parse_line(char *line, size_t line_size)
{
	size_t	key_size;
	size_t	val_size;
	char	*line_start;
	char	**kv_pair;

	line_start = line;
	key_size = 0;
	val_size = 0;
	kv_pair = malloc(sizeof(char *) * 2);
	if (!kv_pair)
		return (NULL);
	while (*line && *line++ != ':')
		key_size++;
	if (!key_size)
		return (NULL);
	kv_pair[0] = trim_spaces_suffix(ft_strndup(line_start, key_size));
	if (!kv_pair[0])
		return (NULL);
	kv_pair[1] = trim_spaces_prefix(ft_strndup(line, line_size - key_size - 1));
	if (!kv_pair[1])
		return (NULL);
	return (kv_pair);
}

ssize_t	ft_parse_dict(char *str, char ***dict_out)
{
	char	**line;
	char	**lines;
	size_t	size;
	size_t	i;

	lines = ft_split(str, "\n");
	free(str);
	size = 0;
	while (lines[size])
		size++;
	if (!dict_out)
		dict_out = malloc(sizeof(line) * size);
	i = 0;
	while (i < size)
	{
		dict_out[i] = parse_line(lines[i], ft_strlen(lines[i]));
		i++;
	}
	return (size);
}

void	dict_mem_cleanup(char ***dict, size_t size)
{
	size_t	i;

	if (!dict)
		return ;
	i = 0;
	while (i < size)
	{
		free(dict[i][0]);
		free(dict[i][1]);
		free(dict[i]);
	}
	free(dict);
}
