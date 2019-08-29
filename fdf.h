#ifndef FDF_H
# define FDF_H

/*
Objectif : utiliser 1 seule ouverture/lecture de fichier pour verifier la
validité du fichier fdf et remmplir la structure map (grace a GNL)
a verifier :
	nom du fichier;
	map rectangulaire non vide uniquement;
	fichier contenant uniquement des espaces ou des nombres(positifs ou negatifs);
	si plusieurs espaces a la suite, les considérer comme 1 seul espace.

Structure de la map :
on utilise GNL qui remplie une str "line", on la verifie, puis on complète la map
en ajoutant
*/
typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_map
{
	t_list			*point_list;
	int				map_length;
	int				map_width;
	int				map_height;
	t_point				**map;
	int				x;
	int				y;
	int				max;
	int				pad;
}					t_map;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int			bpp;
	int			endian;
	int			win_length;
	int			win_width;
	int			keycode;
	int			proj;
	struct s_color	color;
	struct s_map	map;
	struct s_point	point;
	struct s_mov	mov;
}					t_env;