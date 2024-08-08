/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:17:54 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:29:52 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	[F]
	[ Definition ]
	Print the Param(1):"n" by using the [f]ft_putchar.
	
	[ Logic ]
	Divide cases
	1. Mimimun integer
	2. Negative integer
	3. Over 9 integer
	4. One digit integer (0 <= x <= 9)

	[ Memo ]
	Param(2):"pos" always be updated to check the current position.
*/
int	ft_putnbr(int n, int *pos)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		res = ft_putstr("-2147483648", pos);
	else
	{
		if (n < 0)
		{
			res = ft_putchar('-', pos);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, pos);
			ft_putnbr(n % 10, pos);
		}
		if (n < 10)
		{
			res = ft_putchar((n % 10) + '0', pos);
			if (res < 0)
				return (res);
		}
	}
	return (res);
}
