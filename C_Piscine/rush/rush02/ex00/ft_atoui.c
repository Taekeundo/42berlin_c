/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:09:38 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 17:51:13 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#define MAX_VALUE "4294967295"

int	is_possible_uint(char *str)
{
	int	digits;

	digits = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9' || digits > 10)
			return (0);
		str++;
		digits++;
	}
	if (digits < 10)
		return (1);
	if (ft_strncmp(str, MAX_VALUE, digits) > 0)
		return (0);
	return (1);
}

char	*prefix_checks(char *str)
{
	int	stage;

	stage = 0;
	while (*str)
	{
		if (stage == 0 && *str == ' ')
		{
			str++;
			continue ;
		}
		else
			stage++;
		if (stage == 1 && (*str == '-' || *str == '+'))
		{
			if (*str++ == '-')
				return ((void *)0);
		}
		else
			return (str);
	}
	return (str);
}

unsigned int	ft_atoui(char *str)
{
	unsigned int	res;
	unsigned int	digits;

	res = 0;
	digits = 0;
	str = prefix_checks(str);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str++ - '0';
		else
			return (res);
	}
	return (res);
}
