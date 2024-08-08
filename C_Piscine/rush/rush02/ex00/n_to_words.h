/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_to_words.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:45:59 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 21:48:14 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_TO_WORDS_H
# define N_TO_WORDS_H

char	*n_to_words(unsigned int n, char **multi, char **twen, char **tens);
void 	ft_itoa(int num, char* str);

#endif
