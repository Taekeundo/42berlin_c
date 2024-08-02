/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:27 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/09 14:36:25 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*	[F]
	[ What i've learned ]
	1. Function basic format.
			(return)	(function's name)(Parameter)
		ex)	void		ft_putchar(char c)

	2. [f] Write
			write(Param(1), param(2), Param(3));
		ex)	write(1, &c, 1);

		Param(1): FD // File descriptor.
		Param(2): Reference Character to write out to the Param(1): FD.
		Param(3): The number of character for writing.

	[ Definition ]
	Print out Param: "c" to the fd, which is param(1) from the write function.
	fd: 1 -> stdout // terminal.
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
