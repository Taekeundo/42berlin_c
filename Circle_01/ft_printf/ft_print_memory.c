/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:59:22 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:55:35 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	[F]
	Through recursion puthex_u in the puthex_u
	to find remainder with output hexadecimal

	Param(2):"pos" always be updated to check the current position.
*/
int	puthex_u(unsigned long long num, int *pos)
{
	int	result;

	result = 0;
	if (num >= 16)
	{
		puthex_u(num / 16, pos);
		puthex_u(num % 16, pos);
	}
	else
	{
		result = ft_putchar("0123456789abcdef"[num % 16], pos);
		if (result < 0)
			return (result);
	}
	return (result);
}

/*	[F]
	[ Definition ]
	Print the Param(1):"address" by using [f] ft_putchar.

	Print out address at first "0x", cause it's always fixed.
	The address must start with "0x".

	Print out left over hexadecimal (16 digit)

	[ Memo ]
	Param(2):"pos" always be updated to check the current position.
*/
int	ft_print_memory(void *address, int *pos)
{
	int		result;
	char	*str;

	result = 0;
	str = (char *)address;
	if (address == NULL)
		result = ft_putstr("(nil)", pos);
	else
	{
		result = ft_putstr("0x", pos);
		result = puthex_u((unsigned long long)str, pos);
	}
	return (result);
}
