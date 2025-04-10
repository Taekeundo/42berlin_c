/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:16 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:47:17 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_general(char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	exit(1);
}

void	ft_error_and_free_map(char *msg, t_game *game)
{
	ft_printf("[ERROR] %s\n", msg);
	ft_free_map_repo(game->map.repo);
	if (game->map.fill != NULL)
		ft_free_map_fill(game->map.fill, game->map.columns);
	exit(1);
}

void	ft_free_map_fill(char **map, int cols)
{
	int	i;

	if (!map || !*map)
		ft_error_general("Map data not found or invalid.");
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
// 이중포인트 (구조체 속 구조체)

void	ft_free_map_repo(char **target)
{
	int	i;

	if (!target || !*target)
		ft_error_general("Map data not found or invalid.");
	i = 0;
	while (target[i])
	{
		free(target[i]);
		i++;
	}
	free(target);
}

// 이중포인트 (구조체 속 구조체)
// 무언가 traget에 존재한다면
// 이중포인트를 free해줄때는 먼저 안에 포인터들을 free해주고, NULL로 설정까지 해준 뒤 **를 free해준다.
