/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:03:24 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/22 16:59:01 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '*'
			|| base[i] == '/' || base[i] == '%' || base[i] == '='
			|| base[i] == ',' || base [i] == '.'
			|| base[i] < 33 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (j != i && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_l;
	int		divider;

	divider = ft_strlen(base);
	if (check_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		nbr_l = nbr;
		nbr_l *= -1;
		ft_putchar('-');
	}
	else
		nbr_l = nbr;
	if (nbr_l >= divider)
	{
		ft_putnbr_base(nbr_l / divider, base);
		ft_putnbr_base(nbr_l % divider, base);
	}
	if (nbr_l < divider)
		ft_putchar(base[nbr_l]);
}

/*
int		main(void)
{
	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(3, "01");
	write(1, "\n", 1);
	ft_putnbr_base(10, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(3, "poneyvif");	
}
*/
