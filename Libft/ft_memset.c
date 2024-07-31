/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:48:23 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:11:31 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Convert all value in (*dst)string
	with Param(2):val as much as len.

	[ Example ]
	str = "abcdefghijklmnop";
	ft_memset(str, 0, 5);
	-> str = "00000fghijklmnop";
*/
void	*ft_memset(void *dst, int val, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = (unsigned char)val;
		i++;
	}
	return (dst);
}

/*	[ Test ]
	48 == '0' // char

int	main(void)
{
	char	str[10] = "abcdefg";

	printf("%s\n", (char *)ft_memset(str, 48, 3));
	return (0);
}
*/
