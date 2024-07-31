/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:48:43 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:10:02 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Search value('v') in *src(not only string but also anytype) as much as 'n'.

	[ Return ]
	Pointer to the void, which is first founded in memory block.
	No found -> NULL.

	[ Logic ]
	1. Casting : const void *src -> unsgined char *src
	2. while (i < n) -> search
	3. (if) find a 'v' in src -> return(src): address

	[ Difference between ft_strchr ]

							ft_memchr		ft_strchr
	1. Data type		:	(void *)		(char *)
	2. Return type		:	(void *)		(char *)
	3. Searching range	: 	'n'				until '\0'
*/
void	*ft_memchr(const void *src, int v, size_t n)
{
	size_t			i;
	unsigned char	*uc_src;
	unsigned char	uc_v;

	i = 0;
	uc_src = (unsigned char *)src;
	uc_v = (unsigned char)v;
	while (i < n)
	{
		if (uc_src[i] == uc_v)
			return ((void *)(uc_src + i));
		i++;
	}
	return (0);
}

/*	[ Test ]
int	main(void)
{
	char	*str;

	str = "abcedfg";
	printf("%s\n", (char *)ft_memchr(str, 99, 3));
	return (0);
}
*/
