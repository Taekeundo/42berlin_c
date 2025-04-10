#include "cub3d.h"

/**	[F]
 * @brief
 * 	[ Definition ]
 * 	
 * 	[ Logic ]
 * 	1. Read char one by one in the map.
 * 	2. If not allowed char -> error.
 * 	3. Handling newline('\n')
 * 		comparing (longest_ncols) with (current ncols), update.
 * 		= initialize index for (ncols) to '\0'.
 * 		= go to the next line in the map.
 * 	4. Not a newline -> go to the next char(ncols) in the same rows.
 * 	5. Update the current char(*onechar) to the member(cub->char_read).
 * 
 * @param cub 
 * @param one 
 */
static void	validate_map(t_main *cub, char *onechar)
{
	int	i_result_read;

	while (1)
	{
		i_result_read = read(cub->fd, onechar, 1);
		if (i_result_read <= 0)
			break ;
		if (cub->char_read != '0' && cub->char_read != '1'
			&& cub->char_read != 'N' && cub->char_read != 'E'
			&& cub->char_read != 'S' && cub->char_read != 'W'
			&& cub->char_read != ' ' && cub->char_read != '\n')
			ft_error(ERR_INVALID_MAP_CHAR, cub);
		if (cub->char_read == '\n')
		{
			if (cub->map.ncols > cub->map.longest_ncols)
				cub->map.longest_ncols = cub->map.ncols;
			cub->map.ncols = 0;
			cub->map.nrows++;
		}
		else
			cub->map.ncols++;
		cub->char_read = *onechar;
	}
}

/**	[F]
 * @brief
 * 	[ Definition ]
 * 	Check the size of the map in cub3D.
 * 
 * 	[ Logic ]
 * 	1. Initialize (nrows, ncols, longest_ncols) to '0'.
 * 	2. Validate maps (check every single char one by one).
 * 	3. Go to the last rows (cub->map.nrows++).
 * 	4. Update the longest_ncols.
 * 	5. Update the ncols from longest_ncols.
 * 	6. Initialize (map.data_c) to '0'.
 * 
 * @param cub 
 */
void	check_map_size(t_main *cub)
{
	char	one;

	cub->map.nrows = 0;
	cub->map.ncols = 0;
	cub->map.longest_ncols = 0;
	validate_map(cub, &one);
	cub->map.nrows++;
	if (cub->map.ncols > cub->map.longest_ncols)
		cub->map.longest_ncols = cub->map.ncols;
	cub->map.ncols = cub->map.longest_ncols;
	cub->map.data_c = 0;
}

/**	[F]
 * @brief 
 * 	[ Definition ]
 * 	Read one row by one row from the file,
 * 	store it in the cub->map.data_c[row][col] array.
 * 	!! All rows are stored as rectangles of length ncols, !!
 * 	!! which causes the map to have a rectangular shape.  !!
 * 
 * 
 * @param cub 
 * @param row
 */
static void	read_row_fill_rec_shape(t_main *cub, int row)
{
	int		col;
	bool	flag_eol;
	char	one;

	col = 0;
	flag_eol = 0;
	one = 'a';
	while (col < cub->map.ncols)
	{
		if (flag_eol == 0)
		{
			if (read(cub->fd, &one, 1) == 0)
				flag_eol = 1;
			if (col == 0 && one == '\n')
				read(cub->fd, &one, 1);
			if (col > 0 && one == '\n')
				flag_eol = 1;
		}
		if (flag_eol == 0)
			cub->map.data_c[row][col] = one;
		if (flag_eol == 1)
			cub->map.data_c[row][col] = ' ';
		col++;
	}
}

/**	[F]
 * @brief
 * 	[ Definition ]
 * 
 * @param cub 
 */
static void	allocate_map_char(t_main *cub)
{
	int		i;
	t_map	*map;

	i = 0;
	map = &cub->map;
	map->data_c = (char **)malloc(map->nrows * sizeof(char *) + sizeof(char *));
	if (!map->data_c)
		ft_error(ERR_MEM_ROWPTR, cub);
	map->data_c[map->nrows] = 0;
	map->c_alloc = 1;
	while (i < map->nrows)
	{
		map->data_c[i] = (char *)malloc(map->ncols * sizeof(char) + 1);
		if (!map->data_c[i])
			ft_error(ERR_MEM_ROW, cub);
		map->data_c[i][map->ncols] = '\0';
		i++;
	}
}

/**	[F]
 * @brief 
 *	[ Definition ]
 * 
 * 	[ Logic ]
 * 	1. allocate memory for map(2d array) and copy (char type) to the map.
 * 	2. fd no more need -> close.
 * 	3. open map again.
 * 	4. read every words from the file.
 * 	5. 
 * 
 * @param cub 
 */
void	load_and_fill_map(t_main *cub)
{
	char	onechar;
	int		i;
	int		row;

	i = 0;
	row = 0;
	allocate_map_char(cub);
	close(cub->fd);
	cub->fd = open(cub->filename, O_RDONLY);
	if (cub->fd == -1)
		ft_error(ERR_FILE, cub);
	while (i < cub->total_chars_read - 1)
	{
		read(cub->fd, &onechar, 1);
		i++;
	}
	while (row < cub->map.nrows)
		read_row_fill_rec_shape(cub, row++);
	close(cub->fd);
}
