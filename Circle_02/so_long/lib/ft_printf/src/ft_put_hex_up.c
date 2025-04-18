/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:09:30 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:09:31 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_hex_up(unsigned int nbr, char *charset)
{
	char			*temp;
	unsigned int	res;

	if (nbr == 0)
		return (write(1, "0", 1));
	temp = ft_put_n_char(10, '\0');
	ft_get_nbr(temp, nbr, charset, ft_strlen(charset));
	res = write(1, temp, ft_strlen(temp));
	free(temp);
	return (res);
}

/*
int main(void)
{
	unsigned int nb = 4294967294;
	ft_put_hex_up(nb, CHARSET_UHEX);
	printf("\n%X\n", nb);
}*/
