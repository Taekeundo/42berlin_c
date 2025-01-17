/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:08:32 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 12:08:26 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	check whether it's alphabet.
*/
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*	[ Test ]
int main(void)
{
	int i;
	char str[] = "abcde1234}";
	i = 0;
	while (i < 10)
	{
		printf("%d\n", ft_isdigit(str[i]));
		i++;
	}
	return (0);
}
*/
