/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:48:35 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:11:00 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Copy memory from Param(2):"src" to Param(1):"dst" as many as Param(3):"n".

	[ Logic ]
	Case(1): Overlap address of "dst" and "src"
		ex) src: 1001 1001 1002 1003
			dst: 	  	   1002 1003 1004 1005
			----------------------------------
			Copy src from the back.

	Case (2): Not overlap
		ex) src: 1000 1001 1002 1003 // address
			dst: 1010 1011 1012 1013 // address
			------------------------------------
			Copy src from the front.

	[ Memo ]
	if (src == dst || n = 0)
		Don't need to cpy -> return (uc_d).
*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*uc_d;
	unsigned char	*uc_s;

	i = 0;
	uc_d = (unsigned char *)dst;
	uc_s = (unsigned char *)src;
	if (src == dst || n == 0)
		return (uc_d);
	if (uc_d > uc_s)
		while (n--)
			uc_d[n] = uc_s[n];
	else
	{
		while (i < n)
		{
			uc_d[i] = uc_s[i];
			i++;
		}
	}
	return (uc_d);
}

/*	[ Test ]
int	main(void)
{
	char	str1[] = "AAAAAA";
	char	str2[] = "BBBBBB";

	printf("before str1: %s\n", str1);
	printf("before str2: %s\n", str2);
	ft_memmove(str1 + 2, str1, 3);
	printf("After str1: %s\n", str1);
	printf("After str2: %s\n", str2);
	return (0);
}
*/
