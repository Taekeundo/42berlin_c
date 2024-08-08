/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:34:19 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/12 21:07:49 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	k1(int x)
{
	int	tmp;

	tmp = x - 1;
	while (tmp >= 0)
	{
		if (tmp == 0 || tmp - x == -1)
			ft_putchar('o');
		else
			ft_putchar('-');
		tmp --;
	}
}

void	k2(int x)
{
	int	tmp;

	tmp = x - 1;
	while (tmp >= 0)
	{
		if (tmp == 0 || tmp - x == -1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		tmp --;
	}
}

void	rush(int x, int y)
{
	int	tmp;

	if (x < 1 || y < 1)
		return ;
	tmp = y - 1;
	while (tmp >= 0)
	{
		if (tmp == 0 || tmp - y == -1)
			k1(x);
		else
			k2(x);
		tmp --;
		ft_putchar('\n');
	}
}
