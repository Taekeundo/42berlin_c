/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:10:11 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/20 14:14:46 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	return (j);
}

/*	[F]
	[ Definition ]
	Concatenate Param(2):"src" to at the end of the Param(1):"dest"'s,
	until the Param(2):"src" meets with '\0', which is the end of the src string,
	as many as Param(3):"n".
*/
char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
