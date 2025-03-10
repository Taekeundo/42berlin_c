/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:04:28 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/28 14:56:41 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	[ Definition ]
	Calculate power of a given integer type, Param(1):"nb"
	as many times as Param(2):"power", using a loop.

	[ Background ]
	power: nb * nb * nb * ... (power times).

	[ Example ]
	ft_iterative_powe(2, 0) -> 2 ^ 0 = 1
	ft_iterative_powe(3, 1) -> 3 ^ 1 = 3
	ft_iterative_powe(8, 2) -> 8 ^ 2 = 64
*/
int	ft_iterative_power(int nb, int power)
{
	int	i;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = nb;
	while (power > 1)
	{
		nb = i * nb;
		power--;
	}
	return (nb);
}

/*	[ Testing ]
#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_iterative_power(2, 0));
	printf("%d\n", ft_iterative_power(2, 1));
	printf("%d\n", ft_iterative_power(2, 2));
	printf("%d\n", ft_iterative_power(2, 3));
	printf("%d\n", ft_iterative_power(2, 4));
	return (0);
}
*/
