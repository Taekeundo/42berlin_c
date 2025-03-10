/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:05:11 by tkwak             #+#    #+#             */
/*   Updated: 2023/09/09 18:05:14 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *l_str, char *r_str)
{
	char	*result;
	int		i;
	int		j;

	if (l_str == NULL)
	{
		l_str = (char *)malloc(sizeof(char) * 1);
		l_str[0] = '\0';
	}
	if (r_str == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * ((ft_strlen(l_str) + \
		ft_strlen(r_str)) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (l_str[++i] != '\0')
		result[i] = l_str[i];
	j = 0;
	while (r_str[j] != '\0')
		result[i++] = r_str[j++];
	result[ft_strlen(l_str) + ft_strlen(r_str)] = '\0';
	free(l_str);
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
