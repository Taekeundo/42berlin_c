/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:56 by tkwak             #+#    #+#             */
/*   Updated: 2023/10/31 18:47:57 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_readline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (i);
}

// ft_readline
// 0000012\n\0 \n\0 << 끝나는 길이가 다르다.
// 0000012\0\0 . << ft_strlen -> 2\0
// 특정 케이스들이 있을 수 있다.

void	ft_mlx_image_to_window(t_game *game, mlx_image_t *mlx_image, \
			int x, int y)
{
	mlx_image_to_window(game->mlx, mlx_image, x * IMG_WIDTH, y * IMG_HEIGHT);
	if (!mlx_image)
	{
		ft_free_map_repo(game->map.repo);
		ft_error_general("mlx image uninit");
	}
}

void	place_png_to_img(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*my_texture;

	my_texture = mlx_load_png(path);
	if (!my_texture)
		ft_error_and_free_map("wow! texture fucked up.", game);
	*img = mlx_texture_to_image(game->mlx, my_texture);
	mlx_delete_texture(my_texture);
	if (!*img)
		ft_error_and_free_map("wow! image fucked up.", game);
}

int	ft_get_len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
