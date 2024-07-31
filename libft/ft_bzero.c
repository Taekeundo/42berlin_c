/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:49:29 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:33:37 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Erases the data in the 'n' bytes of the memory starting
	at the location pointed by 's', writing zeroes.

	[ Question ]
	why do we have to change the format of (void *s) to (unsigned char *)?
	= To match with the same type each other.
*/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*convert;

	i = 0;
	convert = (unsigned char *)s;
	while (i < n)
	{
		convert[i] = 0;
		i++;
	}
}
