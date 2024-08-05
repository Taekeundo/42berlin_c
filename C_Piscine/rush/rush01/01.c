/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:53:46 by tkwak             #+#    #+#             */
/*   Updated: 2023/02/19 23:22:17 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	parse_param(char *param, int *outer_lines)
{
	int	mult;
	int	i;
	int	j;
	int	result;

	mult = get_multiplier();
	i = 0;
	j = 0;
	result = 0;
	while (param[i])
	{
		if (param[i] >= '1' && param[i] <= '9')
		{
			result += (param[i] - '0') * mult;
			mult /= 10;
			if (result % 10 != 0)
			{
				outer_lines[j] = result;
				j++;
				mult = get_multiplier();
				result = 0;
			}
		}
		i++;
	}
}

int	get_biggest(void)
{
	int	mult;
	int	res;
	int	i;

	mult = get_multiplier();
	i = N;
	res = 0;
	while (i >= 1)
	{
		res += i * mult;
		mult /= 10;
		i--;
	}
	return (res);
}

int	get_smallest(void)
{
	int	mult;
	int	res;
	int	i;

	mult = get_multiplier();
	i = 1;
	res = 0;
	while (i <= N)
	{
		res += i * mult;
		mult /= 10;
		i++;
	}
	return (res);
}

int	get_col_int(int *lines, int pos)
{
	int	i;
	int	mult;
	int	result;

	result = 0;
	i = 0;
	mult = get_multiplier();
	while (i < N)
	{
		result += get_single_digit(lines[i], pos) * mult;
		mult /= 10;
		i++;
	}
	return (result);
}

// check if there is possible solution
int	check_possible_solution(int *lines, int *outer_lines)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < N)
	{
		if (check_row_view(lines[i], get_single_digit(outer_lines[2], N - i),
				get_single_digit(outer_lines[3], N - i)) == 0)
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < N)
	{
		tmp = get_col_int(lines, N - i);
		if (check_number(tmp) == 0 || check_row_view(tmp,
				get_single_digit(outer_lines[0], N - i),
				get_single_digit(outer_lines[1], N - i)) == 0)
			return (0);
		i++;
	}
	return (1);
}
