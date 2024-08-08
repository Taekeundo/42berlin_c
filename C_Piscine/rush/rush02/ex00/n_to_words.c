/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntow1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:36:16 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/26 23:25:13 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"
#include "ft_split.h"
#include "ntow2.h"

void reverse(char* str, int len)
{
    int i = 0, j = len - 1;
    while (i < j) { 
        char temp = str[i];
        str[i++] = str[j];
        str[j--] = temp;
    }
}

void ft_itoa(int num, char* str)
{
    int i = 0, sign = num < 0;
    if (sign) num = -num;
    while (num) {
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    if (i == 0) str[i++] = '0';
    if (sign) str[i++] = '-';
    str[i] = '\0';
    reverse(str, i);
}

void	handle_di(unsigned int digit, char **ans_ptr, char **twen, char **tens)
{
	char	*ans;

	ans = *ans_ptr;
	if (digit > 99)
		ans = handle_hundreds(digit, ans, twen);
	digit = digit % 100;
	if (digit > 0 && digit < 20)
		ans = handle_twenty(digit, ans, twen);
	else if (digit % 10 == 0 && digit != 0)
		ans = handle_tens(digit, ans, tens);
	else if (digit > 20 && digit < 100)
		ans = handle_tt(digit, ans, twen, tens);
	*ans_ptr = ans;
}

char	*n_to_words(unsigned int n, char **multi, char **twen, char **tens)
{
	unsigned int	limit;
	unsigned int	digit;
	unsigned int	t;
	char			*ans;
	char			*result;

	limit = 1000000000;
	digit = 0;
	t = 0;
	if (n == 0)
		return (ft_strdup("Zero"));
	if (n < 20)
		return (ft_strdup(twen[n]));
	while (n > 0)
	{
		if (n < limit)
		{
			limit /= 1000;
			++t;
			continue ;
		}
		digit = n / limit;
		handle_di(digit, &ans, twen, tens);
		ans = malloc(10000);
		if (t < 3)
			ans = handle_multi(t, ans, multi);
		n %= limit;
		limit /= 1000;
	}
	result = (char *)malloc(ft_strlen(ans) + 1);
	ft_strcpy(result, ans);
	return (result);
}
