#include "cub3d.h"

/**	[F]
 * @brief 
 * 	[ Definition ]
 * 	Check the (ac, av) condition, matching with the mendetory pary in PDF.
 * 
 * @param argc
 * @param argv
 */
void	check_user_input(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		ft_error(ERR_ARGS, NULL);
	i = ft_strlen(argv[1]);
	if (ft_strnstr(&argv[1][i - 4], ".cub", 4) == NULL)
		ft_error(ERR_FILETYPE, NULL);
}


