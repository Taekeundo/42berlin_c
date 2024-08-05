/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:43:54 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:16:26 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Compare as much as 'n' bytes of str1 and str2.

	[ Logic ]
	1. If one char, which compares currently, is same each other
		-> go to the next digit.
	2. Finally everything is same -> return (0);
	3. Not same -> return the difference (str1 - str2);
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	if (!n)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < (n - 1))
		i++;
	if (str1[i] == str2[i])
		return (0);
	res = ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (res);
}

/*	[ Test ]
int	main(void)
{
	const char	*str1;
	const char	*str2;

	str1 = "abcde";
	str2 = "abcdf";
	printf("%d\n", ft_strncmp(str1, str2, 5));
}
*/
