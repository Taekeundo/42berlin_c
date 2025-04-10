/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:08:19 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:08:22 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += ft_printf_arg(format, i, ap);
			i++;
		}
		else
			ret += ft_put_char(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}

// int	main()
// {
// 	ft_printf("%s","abcd");
// 	printf("%s","abcd");
// 	return (0);
// }
