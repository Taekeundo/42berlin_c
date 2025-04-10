/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:08:02 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:08:04 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_get_nbr(char *buf, unsigned int nbr, \
					char *charset, int len_base)
{
	unsigned int	digit;
	unsigned int	i;

	if (nbr == 0)
		return (0);
	digit = nbr % len_base;
	i = ft_get_nbr(buf, nbr / len_base, charset, len_base);
	buf[i] = charset[digit];
	return (i + 1);
}
