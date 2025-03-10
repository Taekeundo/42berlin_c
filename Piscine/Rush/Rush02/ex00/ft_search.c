/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:14:14 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 18:25:17 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "ft_read_from_file.h"

char	*find_by_key(char *key, char ***dict, size_t dict_size)
{
	size_t	i;

	i = 0;
	while (i < dict_size)
		if (!ft_strncmp(key, dict[i][0], ft_strlen(key)))
			return (dict[i][1]);
	return ((void *)0);
}

char	*find_by_val(char *val, char ***dict, size_t dict_size)
{
	size_t	i;

	i = 0;
	while (i < dict_size)
		if (!ft_strncmp(val, dict[i][1], ft_strlen(val)))
			return (dict[i][0]);
	return ((void *)0);
}

char	**get_twenties(char ***dict, size_t size)
{
	char	**tw;
	int		i;
	char	temp;

	tw = malloc(sizeof(char *) * 20);
	if (!tw)
		return (NULL);
	i = 0;
	while (i < 11)
	{
		temp = i + '0';
		tw[i] = find_by_key(&temp, dict, size);
		i++;
	}
	while (i < 20)
	{
		temp = '0' + i % 10;
		tw[i] = find_by_key(ft_strapp("1", &temp), dict, size);
	}
	return (tw);
}

char	**get_tens(char ***dict, size_t size)
{
	char	**ts;
	int		i;
	char	temp;

	ts = malloc(sizeof(char *) * 10);
	if (!ts)
		return (NULL);
	i = 0;
	while (i < 10)
	{
		temp = '0' + i;
		ts[i] = find_by_key(ft_strapp(&temp, "0"), dict, size);
	}
	return (ts);
}

char	**get_multipliers(char ***dict, size_t size)
{
	char	**multi;

	multi = malloc(sizeof(char *) * 4);
	if (!multi)
		return (NULL);
	multi[0] = find_by_key("0", dict, size);
	multi[1] = find_by_key("1000000000", dict, size);
	multi[2] = find_by_key("1000000", dict, size);
	multi[3] = find_by_key("10000", dict, size);
	return (multi);
}
