/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:27 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:47:36 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_floor(t_game *game)
{
	place_png_to_img(game, &game->img.floor, PNG_FLOOR);
	place_png_to_img(game, &game->img.wall, PNG_WALL);
	place_png_to_img(game, &game->img.number[0], PNG_NUM0);
}

void	init_player(t_game *game, int x, int y)
{
	place_png_to_img(game, &game->img.player.front.image, PNG_PLAYER_FRONT);
	set_player_position(&game->img.player.front, &game->position);
	mlx_image_to_window(game->mlx, game->img.player.front.image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	init_collect(t_game *game, int x, int y, int *count)
{
	place_png_to_img(game, &game->img.collect[*count].image, PNG_COLLECT);
	game->img.collect[*count].x = x;
	game->img.collect[*count].y = y;
	mlx_image_to_window(game->mlx, game->img.collect[*count].image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
	(*count)++;
}

void	init_exit(t_game *game, int x, int y)
{
	place_png_to_img(game, &game->img.exits[0].image, PNG_EXIT_CLOSE);
	game->img.exits[0].x = x;
	game->img.exits[0].y = y;
	place_png_to_img(game, &game->img.exits[1].image, PNG_EXIT_OPEN);
	game->img.exits[1].x = x;
	game->img.exits[1].y = y;
	mlx_image_to_window(game->mlx, game->img.exits[0].image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
}
