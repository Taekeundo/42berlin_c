/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:08:31 by tkwak             #+#    #+#             */
/*   Updated: 2023/11/01 10:08:32 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_put_hex_low(unsigned int nbr, char *charset)
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

// int main(void)
// {
// 	unsigned int nb = 4294967295;
// 	ft_put_hex_low(nb, CHARSET_LHEX);
// 	printf("\n%x\n", nb);
// }
