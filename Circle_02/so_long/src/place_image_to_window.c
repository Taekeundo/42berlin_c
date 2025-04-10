/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_image_to_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:48 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:52:48 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_floor_with_texture(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.columns)
	{
		x = -1;
		while (++x < game->map.rows)
			ft_mlx_image_to_window(game, game->img.floor, x, y);
	}
	ft_printf("--- floor set . . . . .\n");
}

void	place_layer_with_texture(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.columns)
	{
		x = -1;
		while (++x < game->map.rows)
		{
			if (game->map.repo[y][x] == CHAR_WALL)
				mlx_image_to_window(game->mlx, game->img.wall, \
					x * IMG_WIDTH, y * IMG_HEIGHT);
			else if (game->map.repo[y][x] == CHAR_PLAYER)
				init_player(game, x, y);
			else if (game->map.repo[y][x] == CHAR_COLLLECT)
				init_collect(game, x, y, &game->count);
			else if (game->map.repo[y][x] == CHAR_EXIT)
				init_exit(game, x, y);
		}
	}
	ft_mlx_image_to_window(game, game->img.number[0], 1, game->map.columns - 1);
	ft_printf("--- layer set . . . . .\n");
	game->count = 0;
}
