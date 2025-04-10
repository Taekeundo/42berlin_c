/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:08:42 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:08:43 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_int(int nbr)
{
	char	*str;
	int		res;

	str = ft_itoa(nbr);
	res = ft_put_str(str);
	free(str);
	return (res);
}
