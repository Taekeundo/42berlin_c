/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:09:03 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:09:04 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_uint(unsigned int nbr)
{
	char	*str;
	int		res;

	str = ft_utoa(nbr);
	res = ft_put_str(str);
	free(str);
	return (res);
}
