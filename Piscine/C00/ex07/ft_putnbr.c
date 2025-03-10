/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <pleasepose@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:26:04 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/14 14:51:55 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*	[F]
	[ What i've learned ]
	1. Range of 32-bit signed Integers.
	
		Largest value in integer type :  2147483647
		Smallest value in integer type: -2147483648

		Range: -2147483648 < int n < 2147483647

		why?
		Standard: 32 bits
		Position of digit: 1   2   3   .....   30  31  32
		Cases			 : 2 * 2 * 2 * .....  * 2 * 2 * 2
		= 2^32 cases
		= 4294967296 cases "possible".

		Half of cases for 'positive num': 2147483647 cases
		For '0'							: 1 case
		Half of cases for 'negative num': 2147483648 cases
		---------------------------------------------------
										: 4294967296 cases

	2. Recursive function
		A function that calls itself during its execution.
		Repeat several times as it can call itself with modified parameters.

	[ Definition ]
	Divide cases for Param(1): "nb" and print out one digit by one digit about it.
		Case(1): Min int
		Case(2): Minus
		Case(3): Plus but over one digit
		Case(4): Plus one digit
*/
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}
