/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:35:06 by mcutura           #+#    #+#             */
/*   Updated: 2023/02/26 21:35:22 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_parse_dict.h"
#include "ft_read_from_file.h"
#include "ft_atoui.h"
#include "n_to_words.h"
#include "ft_search.h"
#define DICT_PATH_DEFAULT "./numbers.dict"
#define DEBUG

int		translate(char *nbr, char *dict_path);
char	*get_response(char *in, unsigned int ui, char ***dict, size_t size);

int	main(int ac, char *av[])
{
	int	errno;

	if (ac == 2)
		errno = translate(av[1], DICT_PATH_DEFAULT);
	if (ac == 3)
		errno = translate(av[2], av[1]);
	if (ac == 1)
		return (0);
	if (ac > 3)
		errno = 0;
	if (errno == -1)
		throw_error("Error\n");
	if (errno == -2)
		throw_error("Dict Error\n");
	return (errno);
}

char	*get_response(char *in, unsigned int ui, char ***dict, size_t size)
{
	char	*res;
	char	**multi;
	char	**twenties;
	char	**tens;

	(void)in;
	twenties = get_twenties(dict, size);
	tens = get_tens(dict, size);
	multi = get_multipliers(dict, size);
	res = n_to_words(ui, multi, twenties, tens);
	dict_mem_cleanup(dict, size);
	return (res);
}

int	translate(char *nbr, char *dict_path)
{
	unsigned int	num;
	char			*res;
	char			*stream;
	char			***dict;
	size_t			dict_size;

	if (!is_possible_uint(nbr))
		return (-1);
	num = ft_atoui(nbr);
	stream = ft_read_from_file(dict_path);
	if (!stream)
		return (-2);
	dict = NULL;
	dict_size = ft_parse_dict(stream, dict);
	if (!dict)
		return (-2);
	res = get_response(nbr, num, dict, dict_size);
	if (!res)
		return (-2);
	return (0);
}
