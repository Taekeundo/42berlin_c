/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:02:13 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/27 17:39:48 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_3(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7' || b != '8' || c != '9')
		write(1, ", ", 2);
}

/*	[F]
	[ What i've learned ]
	1. Handling ascending order with while loop.
		int i, int j
		j = i + 1;

	2. User defined function call.
		[f] ft_3 is the function, i made for main function.

	[ Definition ]
	Print the three digit number by following ascending order.
	the current digit order number must be greater than the next digit order number.

	[ Example ]
	012	013 014 015 016 017 018 019
		023 024	025	026	027	028	029
			034	035	     ...    039
		   				.
						.
						.
	123	124	...	129
		234	...	239
		   .
		   .
		   .
	567	568	569
	578	579
	589
	678 679
	689
	789
*/
void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				ft_3(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
