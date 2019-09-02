#include "fdf.h"

int		ft_fdf(char *argv)
{
	t_env	fdf;

	ft_bzero(&fdf, sizeof(t_env));
	ft_create_map(argv, &fdf);
	ft_mlx(&fdf);
	free(*(fdf.map.map));
	ft_bzero(&fdf, sizeof(t_env));
	return (0);
}
