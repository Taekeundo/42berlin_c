#include "cub3d.h"

/** [F]
 * @brief
 * 	[ Definition ]
 * 	
 * 	[ Logic ]
 * 	1. Meet with (N, S, W, E)
 * 	2. If (flag_found) already 1 -> two player -> error.
 * 	3. Save data for the memeber(cub->pos.x, pos.y)
 * 		+ 0.5 // x,y's type is double.
 * 			  // (row, col)
 * 			  // plus x, y as much as 0.5 
 * 			  // In order to set the player's position in the middle of the box.
 * 	4. flag_found -> 1 // already found the position of player.
 * 
 * @param cub 
 * @param row 
 * @param col 
 * @param flag_found 
 */
static void	set_player_pos(t_main *cub, int row, int col, bool *flag_found)
{
	if (cub->map_curr_char == 'N' || cub->map_curr_char == 'S'
		|| cub->map_curr_char == 'W' || cub->map_curr_char == 'E')
	{
		if (*flag_found == 1)
			ft_error(ERR_DUP_PLAYPOS, cub);
		cub->pos.x = row + 0.5;
		cub->pos.y = col + 0.5;
		*flag_found = 1;
	}
}

/**	[F]
 * @brief
 * 	[ Definition ]
 * 	Set direction and view plane of the player at the starting point.
 *
 * 	[ Logic ]
 * 	Same logic with [f] set_player_dir_plane.
 * 
 * @param cub 
 */
static void	set_player_dir_plane_we(t_main *cub)
{
	if (cub->map_curr_char == 'W')
	{
		cub->dir.x = 0;
		cub->dir.y = -1;
		cub->plane.x = 0.66;
		cub->plane.y = 0;
	}
	if (cub->map_curr_char == 'E')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
		cub->plane.x = -0.66;
		cub->plane.y = 0;
	}
}

/**	[F]
 * @brief
 * 	[ Definition ]
 * 	Set direction and view plane of the player at the starting point.
 *	
 * 	[ Backgruond ]
 * 	dir
 * 	= direction vercotr of player
 * 
 * 	plane
 * 	= vie plane vector of camera (2d raycaster 90 degree standard)
 * 	
 * 	Field of View, FOV
 * 	= 2 * arctan(plane length / camera distance)
 * 	= 2 * arctan(0.66 / 1.0)
 * 	= 2 * 33.4 degree (Both directions)
 * 	= 66.8 degree
 * 	= For FPS games, this viewing angle is considered realistic and playable.
 * 
 * 	Standard of direction vector
 * 	North	: dir.x = -1,	plane.y = -0.66
 * 	South	: dir.x =  1,	plane.y =  0.66
 * 	West	: dir.y = -1,	plane.x = -0.66
 * 	East	: dir.y =  1,	plane.x =  0.66
 * 
 * 	[ Detail ]
 * 	1. dir.x = 1, dir.y = 0			// Initial direction vector
 * 	2. plane.x = 0, plane.y = -0.66	// Expand the view to the left.
 * 
 * @param cub 
 */
static void	set_player_dir_plane(t_main *cub)
{
	if (cub->map_curr_char == 'N')
	{
		cub->dir.x = -1;
		cub->dir.y = 0;
		cub->plane.x = 0;
		cub->plane.y = -0.66;
	}
	if (cub->map_curr_char == 'S')
	{
		cub->dir.x = 1;
		cub->dir.y = 0;
		cub->plane.x = 0;
		cub->plane.y = 0.66;
	}
	set_player_dir_plane_we(cub);
}

/** [F]
 * @brief
 * 	[ Definition ]
 * 	Setting the player's position and view angle for the starting point.
 * 
 * @param cub 
 */
void	set_player_pos_dir_plane(t_main *cub)
{
	int		row;
	int		col;
	bool	flag_found;

	row = 0;
	col = 0;
	flag_found = 0;
	while (row < cub->map.nrows)
	{
		col = 0;
		while (col < cub->map.ncols)
		{
			cub->map_curr_char = cub->map.data_c[row][col];
			set_player_pos(cub, row, col, &flag_found);
			set_player_dir_plane(cub);
			col++;
		}
		row++;
	}
	if (flag_found == 0)
		ft_error(ERR_NO_PLAYPOS, cub);
}
