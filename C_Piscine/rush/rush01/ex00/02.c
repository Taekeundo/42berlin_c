/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:54:27 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/19 23:37:51 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#define N 4

int		*find_solution(int *outer_lines, int *lines, int count);
int		*get_all_lines(int *counter);
int		get_single_digit(int nb, int pos);
int		check_param(char *param);
int		check_number(int nb);
int		check_row_view(int row, int left, int right);
int		get_multiplier(void);
void	parse_param(char *param, int *outer_lines);
int		get_biggest(void);
int		get_smallest(void);
int		get_col_int(int *lines, int pos);
int		check_possible_solution(int *lines, int *outer_lines);
int		*sl(int *sol_lines, int *lines, int *params);

void	put_lines_array(int count, int *lines)
{
	int	start;
	int	i;

	start = get_smallest();
	while (i < count)
	{
		if (check_number(start) == 1)
		{
			lines[i] = start;
			i++;
		}
		start++;
	}
}

int	*get_all_lines(int *counter)
{
	int	start;
	int	biggest;
	int	count;
	int	*lines;

	count = 0;
	biggest = get_biggest();
	start = get_smallest();
	while (start <= biggest)
	{
		if (check_number(start) == 1)
			count++;
		start++;
	}
	lines = (int *) malloc(count * 4);
	put_lines_array(count, lines);
	*counter = count;
	return (lines);
}

// bruteforcing for a solution
int	*find_solution(int *outer_lines, int *lines, int count)
{
	int	*sol_lines;
	int	*params;

	params = (int *) malloc(4 * 4);
	params[0] = 0;
	sol_lines = (int *) malloc(N * 4);
	while (params[0] < count)
	{
		params[1] = 0;
		while (params[1] < count)
		{
			params[2] = 0;
			while (params[2] < count)
			{
				params[3] = 0;
				while (params[3] < count)
				{
					sl(sol_lines, lines, params);
					if (check_possible_solution(sol_lines, outer_lines) == 1)
						return (sol_lines);
					params[3] = params[3] + 1;
				}
				params[2] = params[2] + 1;
			}
			params[1] = params[1] + 1;
		}
		params[0] = params[0] + 1;
	}
	return (sol_lines);
}

int	*sl(int *sol_lines, int *lines, int *params)
{
	sol_lines[0] = lines[params[0]];
	sol_lines[1] = lines[params[1]];
	sol_lines[2] = lines[params[2]];
	sol_lines[3] = lines[params[3]];
	return (sol_lines);
}
