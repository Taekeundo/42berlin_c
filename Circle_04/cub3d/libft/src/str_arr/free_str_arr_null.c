#include "lib_main.h"

int	free_str_arr_null(char **str_arr)
{
	int	i;

	i = 0;
	if (!str_arr)
		return (1);
	while (str_arr[i])
	{
		free(str_arr[i]);
		str_arr[i] = NULL;
		i++;
	}
	free(str_arr);
	return (1);
}
