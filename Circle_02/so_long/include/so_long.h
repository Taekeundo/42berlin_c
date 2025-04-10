/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:26:31 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:59:44 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* header*/
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/* mlx library */
# include "MLX42.h"

/* library */
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>

/* define */
# define MAP_WIDTH	288
# define MAP_HEIGHT	288
# define IMG_WIDTH	16
# define IMG_HEIGHT	16
# define NUM_FRAMES	4

/* char */
# define CHAR_MAP	"01PEC"
# define CHAR_FILL	"CEP"
# define IS_FILLED	"1X"
# define CHAR_WALL	49
# define CHAR_EXIT	69
# define CHAR_PLAYER	80
# define CHAR_COLLLECT	67
# define CHAR_FLOOR	48

/* player path */
# define PNG_PLAYER_FRONT	"./asset/char_front/char_front.png"
# define PNG_PLAYER_BACK	"./asset/char_front/char_back.png"
# define PNG_PLAYER_LEFT	"./asset/char_front/char_left.png"
# define PNG_PLAYER_RIGHT	"./asset/char_front/char_right.png"

/* collect path */
# define PNG_COLLECT		"./asset/collect/coffee.png"

/* exit path */
# define PNG_EXIT_OPEN		"./asset/exit/exit1.png"
# define PNG_EXIT_CLOSE		"./asset/exit/exit2.png"

/* wall path */
# define PNG_WALL			"./asset/walls/walls_temp.png"

/* floor path */
# define PNG_FLOOR			"./asset/floor/frame1/frame07.png"

/* number path */
# define PNG_NUM0			"./asset/number/num0.png"
# define PNG_NUM1			"./asset/number/num1.png"
# define PNG_NUM2			"./asset/number/num2.png"
# define PNG_NUM3			"./asset/number/num3.png"
# define PNG_NUM4			"./asset/number/num4.png"
# define PNG_NUM5			"./asset/number/num5.png"
# define PNG_NUM6			"./asset/number/num6.png"
# define PNG_NUM7			"./asset/number/num7.png"
# define PNG_NUM8			"./asset/number/num8.png"
# define PNG_NUM9			"./asset/number/num9.png"

/* struct */
typedef struct s_multi{
	mlx_image_t	*image;
	int			x;
	int			y;
}				t_multi;

typedef struct s_player{
	t_multi		right;
	t_multi		left;
	t_multi		front;
	t_multi		back;
}				t_player;

typedef struct s_img{
	mlx_image_t	*floor;
	t_multi		exits[2];
	t_player	player;
	t_multi		collect[1000];
	mlx_image_t	*wall;
	mlx_image_t	*number[10];
}				t_img;

typedef struct s_map{
	int		rows;
	int		columns;
	int		collects;
	int		player;
	int		exits;
	int		walls;
	int		floor;
	char	**repo;
	char	**fill;
}				t_map;

typedef struct s_position{
	int					x;
	int					y;
	unsigned int		move;
}				t_position;

/* game */
typedef struct s_game{	
	mlx_t		*mlx;
	t_img		img;
	t_map		map;
	t_position	position;
	int			fd;
	int			count;
	int			finish_game;
}				t_game;

/* prototype & main */
void	place_texture(t_game *game);
void	clean_up(t_game *game);

/* error */
void	ft_error_general(char *msg);
void	ft_error_and_free_map(char *msg, t_game *game);
void	ft_free_map_repo(char **target);
void	ft_free_map_fill(char **map, int cols);

/* utility */
int		ft_readline(char *str);
void	ft_mlx_image_to_window(t_game *game, mlx_image_t *mlx_image, \
	int x, int y);
void	place_png_to_img(t_game *game, mlx_image_t **img, char *path);
int		ft_get_len(long nb);

/* valid map */
void	check_surround_wall(int x, int y, t_game *game);
void	check_argument(int ac, char **av);
void	check_possibility_clear_game(t_game *game);
void	collect_map_struct(char c, t_game *game, int x, int y);
void	valid_map(t_game *game);

/* init game */
void	init_value(t_game *game);
void	set_player_position(t_multi *info, t_position *position);
void	init_mlx(t_game *game);

/* init map */
void	map_2d_malloc(t_game *game);
void	check_empty_file(char *line);
void	check_map_len(t_game *game, char *line, int index);
void	init_map(char **av, t_game *game);

/* init image */
void	init_floor(t_game *game);
void	init_player(t_game *game, int x, int y);
void	init_collect(t_game *game, int x, int y, int *count);
void	init_exit(t_game *game, int x, int y);

/* place image to window */
void	place_floor_with_texture(t_game *game);
void	place_layer_with_texture(t_game *game);

/* event */
void	count_moves(mlx_key_data_t keydata, int y, int x, t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	collect_item(t_game *game, int x, int y);
void	if_finish(t_game *game, int x, int y);

/* delete image */
void	delete_item(t_game *game, int x, int y);
void	delete_collectible(t_game *game);
void	delete_player(t_game *game);
void	delete_floor(t_game *game);
void	delete_all_image(t_game *game);

/* display move */
void	display_num_to_window(t_game *game, char *str, int len);
void	delete_num(t_game *game);

/* flood fill */
void	copy_map_to_fill(t_game *game);
void	flood_loop(t_game *game, char **map_fill, char replacement);
void	flood_fill(t_game *game, int x, int y, char replacement);
#endif
