/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:36:29 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/22 16:06:34 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*	[F]
	[ Definition ]
	Convert Param:"str"'s type (ASCII) to (Integer).

	[ Logic ]
	1. Handling space case ('\t,\tab,' ', ..)
	2. Handling sign case (+ or -).
	3. Meet with number -> convert from the last digit.
*/
int	ft_atoi(char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while (str[c] && ((str[c] >= 9 && str[c] <= 13) || str[c] == 32))
		c++;
	while (str[c] && (str[c] == '+' || str[c] == '-'))
	{
		if (str[c] == '-')
		{
			s *= -1;
		}
		c++;
	}
	while (str[c] && (str[c] >= '0' && str[c] <= '9'))
	{
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}

/*	[ Testing ]
#include <stdio.h>
int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "   ---+--+1234ab567";
	str2 = "    0_hg9__dgasdf";
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", ft_atoi(str2));
	return (0);
}
*/
