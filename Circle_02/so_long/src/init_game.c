/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:48:30 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:48:32 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_value(t_game *game)
{
	game->position.x = 0;
	game->position.y = 0;
	game->position.move = 0;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collects = 0;
	game->map.player = 0;
	game->map.exits = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.repo = NULL;
	game->map.fill = NULL;
	game->fd = 0;
	game->count = 0;
	game->finish_game = 0;
}
// finish_game: '게임종료'flag 역할을 하는 field다.

void	set_player_position(t_multi *info, t_position *position)
{
	info->x = position->x;
	info->y = position->y;
	ft_printf("Player position set to (%d,%d)\n", position->x, position->y);
}

void	init_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(IMG_WIDTH * game->map.rows, \
		IMG_HEIGHT * game->map.columns, "so long", true);
	if (!game->mlx)
	{
		ft_error_and_free_map("Failed to initialize MLX.", game);
		exit(1);
	}
}
