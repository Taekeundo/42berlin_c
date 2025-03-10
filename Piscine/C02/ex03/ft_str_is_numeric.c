/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:23:44 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/15 19:58:14 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Check the Param:"str", whether it consist of only number(0-9).
	Yes -> return (1);
	No	-> return (0);
*/
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
