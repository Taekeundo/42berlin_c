/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:53:00 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/19 23:30:05 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
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

int	get_single_digit(int nb, int pos)
{
	int	i;

	i = 1;
	while (i < pos)
	{
		nb /= 10;
		i++;
	}
	return (nb % 10);
}

int	check_param(char *param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		if ((i + 1) % 2 == 0 && param[i] != ' ')
			return (0);
		else if ((i + 1) % 2 == 1)
		{
			if (param[i] < 1 + '0' || param[i] > N + '0')
				return (0);
		}
		i++;
	}
	if (i != (N * N * 2) - 1)
		return (0);
	return (1);
}

// Function to check if the int is a possible row/column
// return 1 if possible, return 0 if not possible
// e.g. 1234 --> possible
// 1123 --> not possible
// 123 --> not possible
// 1235 --> not possible
int	check_number(int nb)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < N - 1)
	{
		num = get_single_digit(nb, i + 1);
		if (num == 0 || num > N)
			return (0);
		j = i + 1;
		while (j < N)
		{
			if (get_single_digit(nb, i + 1) == get_single_digit(nb, j + 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	right_check(int *rightv, int row)
{
	int	i;
	int	biggest;	

	i = 1;
	biggest = 0;
	while (i <= N)
	{
		if (biggest < get_single_digit(row, i))
		{
			biggest = get_single_digit(row, i);
			*rightv = *rightv + 1;
		}
		i++;
	}
}

// check if a row is a possible solution
//(only 1 row) depending on the left and right view
int	check_row_view(int row, int left, int right)
{
	int	i;
	int	biggest;
	int	leftv;
	int	rightv;

	i = N;
	biggest = 0;
	leftv = 0;
	rightv = 0;
	while (i >= 1)
	{
		if (biggest < get_single_digit(row, i))
		{
			biggest = get_single_digit(row, i);
			leftv++;
		}
		i--;
	}
	right_check(&rightv, row);
	if (left == leftv && right == rightv)
		return (1);
	return (0);
}
