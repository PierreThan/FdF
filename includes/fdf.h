/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:23:58 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:31:28 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# include "mlx.h"
# include "../libft/includes/libft.h"

typedef enum
{
	ISO,
	PARALLEL
}	t_proj;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct	s_camera
{
	t_proj		projection;
	int			zoom;
	double		rotx;
	double		roty;
	double		rotz;
	float		z_flattener;
	int			x_offset;
	int			y_offset;
}				t_cam;

typedef struct	s_fdf
{
	t_mlx		mlx;
	int			fd;
	int			depth;
	int			width;
	int			height;
	t_cam		cam;
	t_point		**map;
	char		*file;
	t_point		max;
}				t_fdf;

/*
**		MAIN
*/
int				free_map(t_fdf *fdf);

/*
**      INPUT CHECK
*/

int				parse_file(t_fdf *fdf);

/*
**		TAB
*/
t_point			*create_tab(t_fdf *fdf, char *str);

/*
**		ROTATE
*/
void			rotate_around_oz(t_point *point, double theta);
void			rotate_around_oy(t_point *point, double theta);
void			rotate_around_ox(t_point *point, double theta);

/*
**		PROJECT
*/
void			model_to_view_map(t_fdf *fdf, t_point *view_map);

/*
**		DRAW
*/
void			draw(t_fdf *fdf);

/*
**		COLOR
*/
int				get_color(
					t_point current, t_point start, t_point end, t_point delta);

/*
**		MLX
*/
void			ft_display_window(
					t_mlx *mlx, char *title, int img_width, int img_height);
void			setup_controls(t_fdf *fdf);

/*
**		CONTROLS
*/
void			flatten(int key, t_fdf *fdf);
void			zoom(int key, t_fdf *fdf);
void			rotate(int key, t_fdf *fdf);
void			move(int key, t_fdf *fdf);
#endif
