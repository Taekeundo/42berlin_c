/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:53:31 by tkwak             #+#    #+#             */
/*   Updated: 2023/06/22 15:00:40 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	[F]
	[ Definition ]
	Write Param(1):s to the Param(2): fd.
	One char by one char by using [f]ft_putchar_fd.
	And write the new line at the end of execution.
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (fd < 0)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
	write(fd, "\n", 1);
}
