/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:46:07 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/28 18:36:21 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*	[F]
	[ What i've learned ]
	1. Data type conversion (= type casting)
		For matching the data type with the function.

		When we use it?
		ex) ft_putchar can allow only the (char) type.
			If parent function, which calls [f] ft_putchar,
			can handle only with the (int)type.
			= convert (int) type to (char) by using type casting.
		
		How
			using (+ '0').
		
		Background
			char '0' is 48 in Decimal by following the ASCII manual.

		Example: Convert (int: 96) to (char)
			(char)(i/10) + '0'
			= 9 + '0'
			= 9 + 48
			= 57
			= Decimal 57 -> char '9'.

			(char)(i%10) + '0'
			= 6 + '0'
			= 6 + 48
			= 54
			= Decimal 54 -> char '6'.

	[ Definition ]
	Print the three digit number by following ascending order.
	the current digit order number must be greater than the next digit order number.
*/
void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 98)
	{
		j = i;
		while (++j <= 99)
		{
			ft_putchar((char)(i / 10) + '0');
			ft_putchar((char)(i % 10) + '0');
			ft_putchar(' ');
			ft_putchar((char)(j / 10) + '0');
			ft_putchar((char)(j % 10) + '0');
			if (!(i == 98 && j == 99))
				write(1, ", ", 2);
		}
	}
}

/*	[ Testing ]
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
