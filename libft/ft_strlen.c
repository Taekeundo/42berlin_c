/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:43:41 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 13:59:22 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Get the length of the string.

	[ Logic ]
	1. check each char in string one by one until the string is over.
	2. At the same time, index goes one by one.
	3. Final index is the length of the string.
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;
	char	c;

	if (!str)
	{
		c = *str;
		(void)c;
	}
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
