/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:05:19 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/28 17:28:44 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	If prime	-> return (1);
	Else		-> return (0);

	[ Logic ]
	Divisor: starting '2' and puls one more in every loop.

	[ Background ]
	Prime number:
	Natural number greater than 1 that has only 1 and itself as divisors.
*/
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*	[ Testing ]
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(3));
	printf("%d\n", ft_is_prime(4));
	printf("%d\n", ft_is_prime(5));
	printf("%d\n", ft_is_prime(6));
	printf("%d\n", ft_is_prime(7));
	printf("%d\n", ft_is_prime(8));
	printf("%d\n", ft_is_prime(9));
	printf("%d\n", ft_is_prime(2147483647));
	return (0);
}
*/
