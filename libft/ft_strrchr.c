/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:47:36 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 14:41:05 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Refer to last occurence of a character from a given string.
	= Search from last to first digit. ("string reverse char")

	[ Return ]
	Pointer to the char, which is first founded in string.
	No found -> NULL.
*/
char	*ft_strrchr(const char *str, int search)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)search)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

/* [ Test]
int	main(void)
{
	char	*str;

	str = "dasdasdhknpvhono";
	printf("%s\n", ft_strchr(str, 'h'));
	return (0);
}
*/
