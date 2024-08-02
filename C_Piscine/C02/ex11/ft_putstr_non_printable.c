/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:55:37 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/15 15:08:19 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		a;
	int		b;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			a = hex[str[i] / 16];
			b = hex[str[i] % 16];
			write(1, "\\", 1);
			write(1, &a, 1);
			write(1, &b, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
