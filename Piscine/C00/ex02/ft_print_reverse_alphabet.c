/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:56:17 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/11 21:00:56 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*	[F]
	[ Definition ]
	Reverse version of ex01.
*/
void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}
