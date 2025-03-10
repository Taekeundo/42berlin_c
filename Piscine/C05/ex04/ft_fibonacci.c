/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:04:53 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/28 14:59:08 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Return the Fibonaacci number at the given Param:"index",
	in the Fibobacci sequence.
	
	[ Background ]
	Fibonacci sequence
	Index: 0	1	2	3	4	5	6	7	8	9	10	...
	Value: 0	1	1	2	3	5	8	13	21	44	65	...

	[ Example ]
	ft_fibo(0);		ft_fibo(1);		ft_fibo(2)
	= 0				= 1				= 1 + 1 = 1

	ft_fibo(3);
	= ft_fibo(2) + ft_fibo(1)
	= 1 + 1 = 2
	
	ft_fibo(4);
	= ft_fibo(3) + ft_fibo(2)
	= 2 + 1 = 3
	
	ft_fibo(5);
	= ft_fibo(4) + ft_fibo(3)
	= 3 + 2 = 5

	ft_fibo(6);
	= ft_fibo(5) + ft_fibo(4)
	= 5 + 3 = 8

*/
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*	[ Testing ]
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(1));
	printf("%d\n", ft_fibonacci(2));
	printf("%d\n", ft_fibonacci(3));
	printf("%d\n", ft_fibonacci(4));
	printf("%d\n", ft_fibonacci(5));
	printf("%d\n", ft_fibonacci(6));
	printf("%d\n", ft_fibonacci(7));
	printf("%d\n", ft_fibonacci(8));
	printf("%d\n", ft_fibonacci(9));
}
*/
