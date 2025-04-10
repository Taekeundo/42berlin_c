/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:00 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:47:03 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_item(t_game *game, int x, int y)
{
	int	i;
	int	collect_x;
	int	collect_y;

	collect_x = 0;
	collect_y = 0;
	game->map.repo[y][x] = '0';
	i = -1;
	while (++i < game->map.collects && game->count < game->map.collects)
	{
		if (game->count >= game->map.collects)
			break ;
		collect_x = game->img.collect[i].x;
		collect_y = game->img.collect[i].y;
		if (collect_x == x && collect_y == y)
		{
			mlx_delete_image(game->mlx, game->img.collect[i].image);
			game->count++;
		}
	}
}

void	delete_collectible(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	ft_printf("cols[%d], rows[%d]\n", game->map.columns, game->map.rows);
	while (++y < game->map.columns)
	{
		x = -1;
		while (++x < game->map.rows)
		{
			if (game->map.repo[y][x] == CHAR_COLLLECT)
				delete_item(game, x, y);
		}
	}
	if (game->count != game->map.collects)
		ft_error_and_free_map("could not delete all floor image", game);
	ft_printf("--- all collectible items deleted . . .\n");
}

void	delete_player(t_game *game)
{
	if (!game->img.player.front.image)
		return ;
	mlx_delete_image(game->mlx, game->img.player.front.image);
}

void	delete_floor(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.floor);
}

void	delete_all_image(t_game *game)
{
	delete_collectible(game);
	delete_floor(game);
	delete_player(game);
	delete_num(game);
	mlx_delete_image(game->mlx, game->img.exits[0].image);
	mlx_delete_image(game->mlx, game->img.exits[1].image);
	mlx_delete_image(game->mlx, game->img.wall);
}
