/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:10:04 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/16 15:27:26 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	[F]
	[ Definition ]
	Concatenate Param(2):"src" to at the end of the Param(1):"dest"'s,
	until the Param(2):"src" meets with '\0', which is the end of the src string.
*/
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
