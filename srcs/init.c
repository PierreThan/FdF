#include "fdf.h"

t_point		*t_point_new(int x, int y, int z, int color)
{
	t_point	*new;

	if ((new = ft_memalloc(sizeof(t_point))) != NULL)
	{
		new->x = x;
		new->y = y;
		new->z = z;
		new->color = color;
	}
	return (new);
}

t_map		*t_map_init(int length, int width, int height, t_point **map)
{
	t_map	*new;

	if ((new = ft_memalloc(sizeof(t_map))) != NULL)
	{
		new->length = length;
		new->width = width;
		new->heigth = height;
		new->map = map;
	}
	return (new);
}

t_img		*t_img_init(void *mlx_ptr, int width, int height, int bpp, int endian)
{
	t_img	*new;

	if (((new = ft_memalloc(sizeof(t_img))) != NULL) &&
	((new->img_ptr = mlx_new_image(mlx_ptr, width, height)) != 0))
	{
		new->bpp = bpp;
		new->size_l = bpp * width;
		new->endian = endian;
		new->data = (int*)(mlx_get_data_adrr(new->img_ptr, &(new->bpp), &(new->size_l), &(new->endian)));
	}
	return (new);
}
t_mlx		*t_mlx_init(int win_width, int win_height)
{
	t_mlx	*new;

	if (((new = ft_memalloc(sizeof(t_mlx))) != NULL) && (new->mlx_ptr))
}
