/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:43:26 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/06 10:44:15 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**	[F]
 * 
 * 	[ use function printing map in terminal ]
 *  display_cub_info(&cub);
 * 	
 * @param argc
 * @param argv
 * @return int
 */
int	main(int argc, char **argv)
{
	t_main	cub;

	check_user_input(argc, argv);
	init_cub(argv, &cub);
	if (ft_map_surround_wall(&cub))
		ft_error(ERR_MAP_WALLS, &cub);
	init_window(&cub);
	mlx_key_hook(cub.mlx, &keyhook, &cub);
	mlx_close_hook(cub.mlx, &closehook, &cub);
	mlx_loop_hook(cub.mlx, ft_raycast, &cub);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	free_cub(&cub);
	return (0);
}