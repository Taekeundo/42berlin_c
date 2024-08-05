/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:05:06 by tkwak             #+#    #+#             */
/*   Updated: 2023/03/01 12:52:27 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*	[F]
	[ Definition ]
	If the input number Param:"nb" is a perfect square,
	it returns its square root, otherwise it returns 0.

	[ Example ]
	nb: 2 -> l = 2; -> 2 * 2 <= l ?? -> X -> return (0);
	nb: 3 -> l = 3; -> 2 * 2 <= 3 ?? -> X -> return (0);
	nb: 4 -> l = 4; -> 2 * 2 <= 4 ?? -> O -> return (2);

	nb: 5 -> l = 5; -> 2 * 2 <= 5 ?? -> O -> index++;
					-> 3 * 3 <= 5 ?? -> X -> return (0);
	
	nb: 6 -> l = 6; -> 2 * 2 <= 6 ?? -> O -> index++;
					-> 3 * 3 <= 6 ?? -> X -> return (0);
	
	nb: 7 -> l = 7; -> 2 * 2 <= 7 ?? -> O -> index++;
					-> 3 * 3 <= 7 ?? -> X -> return (0);
	
	nb: 8 -> l = 8; -> 2 * 2 <= 8 ?? -> O -> index++;
					-> 3 * 3 <= 8 ?? -> X -> return (0);

	nb: 9 -> l = 9; -> 2 * 2 <= 9 ?? -> O -> index++;
					-> 3 * 3 <= 9 ?? -> O -> return (3);
*/
int	ft_sqrt(int nb)
{
	long	index;
	long	l;

	l = nb;
	if (l <= 0)
		return (0);
	if (l == 1)
		return (1);
	index = 2;
	if (l >= 2)
	{
		while (index * index <= l)
		{
			if (index * index == l)
			{
				return (index);
			}
			index++;
		}
	}
	return (0);
}

/*	[ Testing ]
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(3));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(6));
	printf("%d\n", ft_sqrt(7));
	printf("%d\n", ft_sqrt(8));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147483647));
	return (0);
}
*/
