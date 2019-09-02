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

int		get_file(int fd, t_list **file)
{//ATTENTION : la map est "retournée" : 1ere ligne = dernier elem de la liste
	char	*line;
	char	**tab;
	t_lst	*tmp;
	int		width;

	*file = NULL;
	width = 0;
	while (get_next_line(fd, &line) > 0) // a verifier
	{
		if ((tab = ft_strsplit(line, ' ')) == NULL)
			return (-1);
		if ((tmp = ft_lstnew(tab, sizeof(tab))) == NULL)
		{
			free(tab);
			return (-1);
		}
		if (*file == NULL)
			*file = tmp;
		else
			ft_lstadd(file, tmp);
		free(tab);
		width++;
	}
	return (width);
}

t_point		*create_point(char *str)
{
//verifie qu'on a bien 1 entier positif
//potentiellement suivi d'une virgule puis de la couleur en hexa->sinon blanc
//renvoie le t_point correspondant
}

int			*create_map(t_list *file, t_map *map)
{
//definie la lenght de la map selon la premiere (ou derniere) ligne
//malloc la map->map
//verifie la length de chaque ligne, et chaque point, puis compléte map
}

/*
int		get_file(int fd, char **file, t_map *map)
{	//extrait le fichier fdf en 1 string, remplie les dim 2D de map
	// NE PAS S'OCCUPER DE LA LENGTH -> ERREUR SI COULEUR DEFINIE
	char	*line;
	char	*tmp;
	int		width;
	int		ret;

	width = 0;
	*file = NULL;
	while ((ret = get_next_line(fd, &line)) > 0) // a verifier
	{
		tmp = *file;
		if (tmp)
		{
			if ((map->length != ft_strlen(*line)) ||		//à corriger
			((*file = ft_strjoin(*file, *line)) == NULL))
				return (-1);
			free(tmp);
		}
		else
		{
			map->length = ft_strlen(*line);
			*file = ft_strdup(*line);
		}
		width++;
	}
	map->width = width;
	return (ret);
}
char	***strtotab3(char *file, t_map	*map)
{
	char	***tab;
	int		i;
	int		j;

	if ((tab = (char***)malloc(map->width * sizeof(char**))) != NULL)
	{
		i = 0;
		while (i < map->width)
		{
			j = 0;
			while
			tab[i] = ft_strsplit(file, '\n')
		}
	}

}
*/

int		parse_file(int fd, t_map *map)
{
	//verifie la map dans le fichier fdf
	//et remplie la structure map
	t_list	*file;
	int		width;

	if ((map->width = get_file(fd, &file)) != -1)
	{
		if ((createmap(file, map)) == -1)
		{
			ft_printf("usage error - map error");
			return (-1);
		}
	}
	return (-1)
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
	t_mlx	mlx;
	int		fd;

	if ((fd = open(argv[1])) == -1)		// a compléter
	{
		//OPEN ERROR MESSAGE
		return (-1);
	}
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
