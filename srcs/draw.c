/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:51:23 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:51:25 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"
#include <math.h>

void	point_to_img(t_fdf *fdf, t_point p)
{
	if (p.x > 0 && p.x < WIN_WIDTH && p.y > 0 && p.y < WIN_HEIGHT)
	{
		if (p.color != 0xFFFFFF)
			fdf->mlx.img.data[p.x + p.y * WIN_WIDTH] = p.color;
		else
			fdf->mlx.img.data[p.x + p.y * WIN_WIDTH] = 16777215;
	}
}

void	draw_line(t_fdf *fdf, t_point p0, t_point p1)
{
	t_point	data[3];
	int		error[2];

	data[0].x = FT_ABS(p1.x - p0.x);
	data[0].y = FT_ABS(p1.y - p0.y);
	data[1].x = p0.x < p1.x ? 1 : -1;
	data[1].y = p0.y < p1.y ? 1 : -1;
	error[0] = data[0].x - data[0].y;
	data[2] = p0;
	while (data[2].x != p1.x || data[2].y != p1.y)
	{
		data[2].color = get_color(data[2], p0, p1, data[0]);
		point_to_img(fdf, data[2]);
		error[1] = error[0];
		if (error[1] > -data[0].x)
		{
			error[0] -= data[0].y;
			data[2].x += data[1].x;
		}
		if (error[1] < data[0].y)
		{
			error[0] += data[0].x;
			data[2].y += data[1].y;
		}
	}
}

void	draw_map(t_fdf *fdf, t_point *view_map)
{
	int index;

	index = 0;
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->mlx.img.img_ptr);
	fdf->mlx.img.img_ptr =
		mlx_new_image(fdf->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->mlx.img.data = (int*)mlx_get_data_addr(fdf->mlx.img.img_ptr,
		&(fdf->mlx.img.bpp), &(fdf->mlx.img.size_l), &(fdf->mlx.img.endian));
	while (index < fdf->width * fdf->height)
	{
		if (index / fdf->width < fdf->height - 1)
		{
			draw_line(fdf, view_map[index], view_map[index + fdf->width]);
		}
		if (index % fdf->width < fdf->width - 1)
		{
			draw_line(fdf, view_map[index], view_map[index + 1]);
		}
		index++;
	}
	point_to_img(fdf, view_map[index - 1]);
}

void	show_map(t_fdf *fdf, t_point *map)
{
	int i;
	int j;
	int	n;

	n = 1;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			while (map[i * fdf->width + j].z < 1000 / n)
			{
				ft_putchar(' ');
				n *= 10;
			}
			n = 1;
			ft_putnbr(map[i * fdf->width + j].z);
			ft_putchar('\t');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	draw(t_fdf *fdf)
{
	t_point	view_map[fdf->width * fdf->height];

	model_to_view_map(fdf, view_map);
	draw_map(fdf, view_map);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr,
		fdf->mlx.img.img_ptr, 0, 0);
}
