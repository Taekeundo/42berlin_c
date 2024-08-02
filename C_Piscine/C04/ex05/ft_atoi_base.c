/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:36:59 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/22 18:57:21 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base1(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '*'
			|| base[i] == '/' || base[i] == '%' || base[i] == '='
			|| base[i] >= 9 && base[i] <= 13 || base[i] == 32
			|| base[i] == ',' || base[i] == '.' || base[i] < 33
			|| base[i] > 126)
			return (0);
		else
			i++;
	}
	return (i);
}

int	check_base2(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_atoi(char *str)
{
	int	c;
	int	s;

	c = 0;
	s = 1;
	while (str[c] && ((str[c] >= 9 && str[c] <= 13) || str[c] == 32))
		c++;
	while (str[c] && (str[c] == '+' || str[c] == '-'))
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	return (s);
}

int	ft_atoi_base(char *str, char *base)
{
	int	c;
	int	s;
	int	res;
	int	len;

	c = 0;
	res = 0;
	s = check_atoi;
	len = check_base1(base);
	if ((check_base1(base) != 0) && (check_base2(base) != 0))
	{
		while (str[c] && (str[c] >= '0' && str[c] <= '9'))
		{
			res = (str[c] - '0') + (res * divider);
			c++;
			return (res * s);
		}
	}
	return (0);
}

/*
int main(void)
{
    char    *str;

    *str = "1234456";
    ft_atoi_base(str, "0123456789");
    write(1, "\n", 1);
    return (0);
}
*/
