/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:08:40 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/15 17:57:18 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Check the Param:"str", whether it consist of only pritable char.
	Yes -> return (1);
	No	-> return (0);

	[ Memo ]
	Non-printable characters in C
	Decimal: 0 - 31 && 127
*/
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
			return (0);
		i++;
	}
	return (1);
}
