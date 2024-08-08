/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 04:33:20 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 04:35:42 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_FROM_FILE_H
# define FT_READ_FROM_FILE_H

char	*ft_read_from_file(const char *filepath);
void	throw_error(char *msg);
char	*ft_strapp(char *s1, char *s2);

#endif
