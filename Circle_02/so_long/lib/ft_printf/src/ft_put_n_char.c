/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_n_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:09:41 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:09:42 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_n_char(int n, char c)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc(n + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < n)
	{
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
