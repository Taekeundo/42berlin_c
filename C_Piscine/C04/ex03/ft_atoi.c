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

/*
#include <stdio.h>
*/

#include <stdlib.h>

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

/*
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

/*
c = count // s = sign (+ or -)
when encount isspace // 9 <= str[i] <= 13 || str[i] == 32
space, tab // move to the next Char.
when encount  +,- // especially if - // s * -1 == make a number positive.
when encount number // express all charctor as a interger.
*/
