#include <stdio.h>
#include "mlx.h"
#include "libft.h"

//cc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

int		check_input(int ac, char **argv)
{
	int	i;

	if (ac != 2)
		ft_printf("usage error - use 1 and only 1 argument");
		return (0);
	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'f' || argv[1][i - 2] != 'd' || argv[1][i - 3] != 'f'
	|| argv[1][i - '4'] != '.')
	{
		ft_printf("usage error - use a .fdf file");
		return (0);
	}
	return (1);
}

int		parse_file(int fd, t_map *map)
{
	//verifie la map dans le fichier fdf
	//et remplie la structure map
}

int		ft_fdf(t_map *map, t_mlx *mlx)
{
	// visuel de la map :
		// algo de tracé de segments
		// differents angles de vus : isometrique/parallele
		// matrice de rotation
	//menu, interaction (clavier, souris) : zoom, deplacement, rotation, flatten
	//free
}

// Idée de main :
int		main(int ac, char **argv)
{
	t_map	map;
	t_env	env;

	if (check_input(ac, argv) == 0)
		return (-1);
	else if (parse_file(fd, map) == 0)
		return (-1);
	else
		ft_fdf(map, mlx);
	return (0);
}

//BROUILLON POUR SET UN ENV GRAPHIQUE :
void	set_env()
{
	int		bpp = 32; // un pixel = 4 chars, 1 char = 8 bits, so 8*4 = 32
	int     size_line; //nb de pixel par ligne * le nombre de chars par pixel (ici 4 : RGB + ALPHA)
	int     endian = 0; // 0 ou 1, ici 0 pour les macs de 42
	void    *mlx_ptr = mlx_init();
	void    *img_ptr = mlx_new_image(mlx_ptr, 800, 600); // 800 = width ; 600 = height
	char    *img_data =  mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	size_line = 4*800;
	int		i = 0;
	int		X = 50;
	int		Y = 50;
	while (i < 150)
	{
	img_data[X * 4 + 4 * size_line * Y] = 254;
	img_data[X * 4 + 4 * size_line * Y + 1] = 254;
	img_data[X * 4 + 4 * size_line * Y + 2] = 254;
	i++;
	X++;
	}
	printf("%s\n", img_data);
    void	*win_ptr = mlx_new_window(mlx_ptr, 1200, 1000, "test");
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 150, 150);
	mlx_loop(mlx_ptr);
}
