/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:58:43 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 15:41:47 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	if (str == NULL)
		return (0);
	while (str[index] != '\0')
	{
		if (str[index] != c)
		{
			words++;
			while (str[index] != c && str[index] != '\0')
				index++;
		}
		else
			index++;
	}
	return (words);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	int		size;
	char	**res;

	i = 0;
	j = 0;
	words = ft_count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		res[j] = ft_substr(s, i, size);
		i += size;
		j++;
	}
	res[j] = NULL;
	return (res);
}
