/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:44:05 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 14:28:44 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Copy the Param(2):src to the Param(1):dst as much as Param(3):dstsize.

	[ Return ]
	Length of Param(2):src

	[ Memo ]
	Safer than strncpy.

	strlcpy:
		'\0' is always at the end of string.
		We can know how the length of the original string(src) is.

	strncpy:
		If (dstsize > srcsize), fill the remaining space to the NULL.
		It's wasting useless memory.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
