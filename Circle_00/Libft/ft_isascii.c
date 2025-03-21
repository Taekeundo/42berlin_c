/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:09:58 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:08:06 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	check whether it's ascii.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*	[ Test ]
int	main(void)
{
	int		i;
	char	*str;

	str[] = "abcde//€34}";
	i = 0;
	while (i < 10)
	{
		printf("%d\n", ft_isascii(str[i]));
		i++;
	}
	return (0);
}
*/
