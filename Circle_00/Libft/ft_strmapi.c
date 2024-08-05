/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:25:59 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:16:07 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Applies a given function, Param(2): "f"
	to each character of the input string, Param(1): "s"
	to produce a new string.

	[ Test ]
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	
	char to_upper(unsigned int i, char c)
	{
		(void)i;	// Don't use the index in this function.
		return (toupper(c));
	}

	int main()
	{
		char const *str1 = "abcdefg";
		char *result = ft_strmapi(str1, to_upper);

		if (result != NULL)
		{
			printf("Origin: %s\n", str1);
			printf("Modified: %s\n", result);
			free(result);
		}
		else
			printf("Allocation failed\n");
		return (0);
	}

	[ Result ]
	Origin: abcdefg
	Modified: ABCDEFG
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	unsigned int	len;

	res = NULL;
	i = 0;
	len = (unsigned int)(strlen(s));
	if (s == NULL || f == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
