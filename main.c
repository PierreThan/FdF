#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl_fd("Usage : ./fdf <filename> [ case_size z_size ]", 2);
	else if (ft_check(argv[1]) == -1)
		return (-1);
	else
		ft_fdf(argv[1]);
	return (0);
}
