/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:34:54 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/19 23:42:37 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
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

// getting the mutiplier to convert string numbers to actual ints
int	get_multiplier(void)
{
	int	i;
	int	mult;

	i = 0;
	mult = 1;
	while (i < N - 1)
	{
		mult *= 10;
		i++;
	}
	return (mult);
}

void	put_solution(int *sol)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			c = get_single_digit(sol[i], N - j) + '0';
			write(1, &c, 1);
			if (j == N - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
}

// startpoint
int	main(int argc, char *argv[])
{
	int	*outer_lines;
	int	*sol_lines;
	int	count;
	int	*p_lines;

	outer_lines = (int *) malloc(4 * 4);
	if (argc != 2 || check_param(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	parse_param(argv[1], outer_lines);
	p_lines = get_all_lines(&count);
	sol_lines = find_solution(outer_lines, p_lines, count);
	if (sol_lines == 0)
	{
		write(1, "Error\n", 6);
	}
	put_solution(sol_lines);
	free(sol_lines);
	free(p_lines);
	free(outer_lines);
	return (0);
}
