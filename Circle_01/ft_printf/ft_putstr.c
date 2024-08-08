/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:21 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:30:58 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	[F]
	[ Definition ]
	Print the Param(1):"str" by using [f] ft_putchar.

	[ Why using 'unsigned' type? ]
	'i' is index, must be positive number.

	[ Memo ]
	Param(2):"pos" always be updated to check the current position.
*/
int	ft_putstr(char *str, int *pos)
{
	long unsigned int	i;
	int					result;

	i = 0;
	result = 0;
	if (!str)
		ft_putstr("(null)", pos);
	else
	{
		while (str[i] != '\0')
		{
			result = ft_putchar(str[i], pos);
			if (result < 0)
				return (result);
			i++;
		}
	}
	return (result);
}

/*	[ Testing ]
int	main(void)
{
	char	*str = "abcdef";
	int		pos = 6;
	ft_putstr(str, &pos);
	printf("\n%s\n", str);
	return (0);
}
if there is error, return -1
if there is no error, return 0; 
*/
