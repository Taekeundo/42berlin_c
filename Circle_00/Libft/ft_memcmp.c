/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:48:48 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:10:35 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Compare as much as 'n' bytes of s1 and s2.

	[ Logic ]
	Same with [f]ft_strncmp.

	[ Difference between ft_strncmp ]

							ft_memcmp		ft_strncmp
	1. Data type		:	(void *)		(char *)
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
		i++;
	}
	return (0);
}

/*	[ Test ]
int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "abc12";
	str2 = "abc42";
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("\n");
	printf("orginal cmp: %d\n", memcmp(str1, str2, 5));
	printf("result of cmp: %d\n", ft_memcmp(str1, str2, 5));
	return (0);
}
*/
