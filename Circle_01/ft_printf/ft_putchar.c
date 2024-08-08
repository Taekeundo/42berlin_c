/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:59:11 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:25:54 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	[F]
	[ Definition ]
	Print the Param(1):"c"

	[ Memo ]
	Param(2):"pos" always be updated to check the current position.
*/
int	ft_putchar(char c, int *pos)
{
	*pos = *pos + 1;
	return (write(1, &c, 1));
}
