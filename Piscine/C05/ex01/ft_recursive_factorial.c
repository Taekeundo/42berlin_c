/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:04:13 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/28 14:55:30 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Check the reference, C05, ex00, almost same logic with that.
	The only difference is, the direction of the multiplying.

	factorial: 5 * 4 * 3 * 2 * 1
	recursive: 1 * 2 * 3 * 4 * 5
*/
int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/*	[ Testing ]
#include <stdio.h>

int	main (void)
{
	printf("%d\n", ft_recursive_factorial(1));
	printf("%d\n", ft_recursive_factorial(2));
	printf("%d\n", ft_recursive_factorial(3));
	printf("%d\n", ft_recursive_factorial(4));
	printf("%d\n", ft_recursive_factorial(5));
	printf("%d\n", ft_recursive_factorial(6));
	printf("%d\n", ft_recursive_factorial(7));
	printf("%d\n", ft_recursive_factorial(8));
	printf("%d\n", ft_recursive_factorial(9));
	return (0);
}
*/
