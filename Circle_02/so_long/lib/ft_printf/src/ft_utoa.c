/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:09:55 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:09:56 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_getlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int nbr)
{
	char	*buf;

	if (nbr == 0)
		return (ft_strdup("0"));
	buf = (char *)malloc(sizeof(char) * f_getlen(nbr) + 1);
	buf[f_getlen(nbr)] = '\0';
	ft_get_nbr(buf, nbr, CHARSET_DEC, 10);
	return (buf);
}
