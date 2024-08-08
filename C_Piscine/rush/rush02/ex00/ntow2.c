/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntow2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:01:38 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/26 23:08:27 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"
#include "ft_split.h"
#include "n_to_words.h"

char	*handle_hundreds(unsigned int digit, char *ans, char **twen)
{
	char	buf[100];

	ft_itoa(digit / 100, buf);
	ft_strcat(ans, twen[digit / 100]);
	ft_strcat(ans, " Hundred ");
	return (ans);
}

char	*handle_twenty(unsigned int digit, char *ans, char **twen)
{
	ft_strcat(ans, twen[digit]);
	ft_strcat(ans, " ");
	return (ans);
}

char	*handle_tens(unsigned int digit, char *ans, char **tens)
{
	char	buf[100];

	ft_itoa(digit / 10, buf);
	ft_strcat(ans, tens[digit / 10 - 1]);
	ft_strcat(ans, " ");
	return (ans);
}

char	*handle_tt(unsigned int digit, char *ans, char **twen, char **tens)
{
	char	buf[100];

	ft_itoa(digit / 10, buf);
	ft_strcat(ans, tens[digit / 10 - 1]);
	ft_strcat(ans, " ");
	ft_strcat(ans, twen[digit % 10]);
	ft_strcat(ans, " ");
	return (ans);
}

char	*handle_multi(unsigned int t, char *ans, char **multi)
{
	ft_strcat(ans, multi[t]);
	ft_strcat(ans, " ");
	return (ans);
}
