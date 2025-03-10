/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:03:36 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/11 21:08:18 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*	[F]
	[ What i've learned ]
	1. If, else condition.
		if -> else if -> else if -> ... -> else
		---				---				   ---
		start		   middle			   final

	[ Definition ]
	Check the Param: "n" whether it's - or +.
	If) minus		-> N print.
	Else if) plus	-> P print.
*/

void	ft_is_negative(int n)
{
	char	negative;
	char	positive;

	negative = 'N';
	positive = 'P';
	if (n < 0)
	{
		write(1, &negative, 1);
	}
	else
	{
		write(1, &positive, 1);
	}
}
