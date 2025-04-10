/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:09:12 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:09:13 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *fmt, int i, va_list ap)
{
	if (fmt[i + 1] == '%')
		return (ft_put_char(fmt[i + 1]));
	else if (fmt[i + 1] == 'c')
		return (ft_put_char(va_arg(ap, int)));
	else if (fmt[i + 1] == 's')
		return (ft_put_str(va_arg(ap, char *)));
	else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
		return (ft_put_int(va_arg(ap, int)));
	else if (fmt[i + 1] == 'u')
		return (ft_put_uint(va_arg(ap, unsigned int)));
	else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
	{
		if (fmt[i + 1] == 'X')
			return (ft_put_hex_up(va_arg(ap, unsigned int), CHARSET_UHEX));
		else
			return (ft_put_hex_low(va_arg(ap, unsigned int), CHARSET_LHEX));
	}
	else if (fmt[i + 1] == 'p')
		return (ft_put_ptr(va_arg(ap, unsigned long)));
	else
		return (0);
}
