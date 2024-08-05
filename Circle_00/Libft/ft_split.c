/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:48:29 by tkwak             #+#    #+#             */
/*   Updated: 2023/09/06 15:01:15 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Logic ]
	char *s	: abc def
	c		: ' ' (space bar)

	row		index	prvc	
	1		0		a
	1		1		b
	1		2		c
	2		3		' '
	2		4		d
	2		5		e
	2		6		f
	2		7		'\0'

	If 'c' == '\0'
		row - 1 // make it back to the 0.
*/
int	countrow(char const *s, char c)
{
	int		row;
	char	prvc;
	int		index;

	row = 0;
	prvc = 0;
	index = 0;
	if (s[index] != c && s[index] != 0)
		row++;
	while (s[index])
	{
		if (prvc == c && s[index] != c)
			row++;
		prvc = s[index];
		index++;
	}
	if (c == '\0')
		row = row - 1;
	return (row);
}

/*	[F]
	Free double array.
*/
int	double_free(char **str, int i)
{
	if (str[i] == NULL)
	{
		while (i >= 0)
		{
			free(str[i]);
			i--;
		}
		free(str);
		return (-1);
	}
	return (1);
}

/*	[F]
	[ Definition ]
	Allocate memory and assign line by line,
	which is seperated by Param(3):delimiter

	[ Memo ]
	ft_substr:
	cut the string from Param(2): 'start' to Param(3): 'i - start'.

	If fails to execute [f]ft_substr
	-> free memory which is until now allocated.
*/
char	**linebyline(char **str, char const *s, char delimiter)
{
	int	i;
	int	word_index;
	int	start;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		if (s[i] != delimiter)
		{
			start = i;
			while (s[i] && s[i] != delimiter)
				i++;
			str[word_index] = ft_substr(s, start, i - start);
			if (double_free(str, word_index) < 0)
				return (NULL);
			word_index++;
		}
		else
			i++;
	}
	str[word_index] = NULL;
	return (str);
}

/*	[F]
	[ Definition ]
	Split Param(1):'s' by the Param(2): 'delimiter'.

	[ Logic ]
	1. Count rows.
	2. Allocate memory as much as rows.
	3. Assign line by line to each row's memory.
	4. Return (Double array).
*/
char	**ft_split(char const *s, char delimiter)
{
	char	**str;
	int		row;

	row = countrow(s, delimiter);
	str = (char **)malloc((row + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	str = linebyline(str, s, delimiter);
	if (str == NULL)
	{
		free (str);
		return (NULL);
	}
	return (str);
}
