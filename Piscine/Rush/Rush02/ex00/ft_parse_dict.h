/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 04:31:38 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 04:32:31 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_DICT_H
# define FT_PARSE_DICT_H

ssize_t	ft_parse_dict(char *str, char ***dict_out);
void	dict_mem_cleanup(char ***dict, size_t size);

#endif
