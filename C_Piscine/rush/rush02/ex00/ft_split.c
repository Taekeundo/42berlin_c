/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:28:41 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 04:02:36 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

int	is_sep(char c, char *sep)
{
	if (!c)
		return (1);
	while (*sep)
		if (*sep++ == c)
			return (1);
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	size_t	i;
	size_t	n;

	n = ft_strlen(str);
	copy = malloc(n + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strndup(char *str, int n)
{
	char	*copy;
	int		i;

	copy = malloc(n + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	count_words(char *str, char *charset)
{
	int	c;
	int	i;
	int	word;

	c = 0;
	i = 0;
	word = 0;
	while (str[i])
	{
		if (is_sep(str[i++], charset))
		{
			if (!word)
				continue ;
			c++;
			word = 0;
		}
		else
			word++;
	}
	if (word)
		c++;
	return (c);
}

char	**get_split(char *str, char *charset, char **strs)
{
	int	i;
	int	c;
	int	word;

	i = 0;
	c = 0;
	word = 0;
	while (str[i])
	{
		if (is_sep(str[i++], charset))
		{
			if (!word)
				continue ;
			strs[c++] = ft_strndup(&str[i - word - 1], word - 1);
			word = 0;
		}
		else
			word++;
	}
	if (word)
		strs[c] = ft_strndup(&str[i - word], word - 1);
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		count;

	count = count_words(str, charset);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	strs = get_split(str, charset, strs);
	strs[count] = 0;
	return (strs);
}
