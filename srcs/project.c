/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:52:03 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:52:05 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include <math.h>

static void	iso(t_point *p)
{
	int tmp_x;
	int tmp_y;

	tmp_x = p->x;
	tmp_y = p->y;
	p->x = (tmp_x - tmp_y) * cos(0.523599);
	p->y = -p->z + (tmp_x + tmp_y) * sin(0.523599);
}

static void	projection(t_fdf *fdf, t_point *view_map, int index)
{
	int	x;
	int	y;

	x = index % fdf->width;
	y = index / fdf->width;
	view_map[index].color = fdf->map[y][x].color;
	view_map[index].x = x * fdf->cam.zoom;
	view_map[index].y = y * fdf->cam.zoom;
	view_map[index].z = fdf->map[y][x].z * fdf->cam.zoom / fdf->cam.z_flattener;
	rotate_around_ox(&view_map[index], fdf->cam.rotx);
	rotate_around_oy(&view_map[index], fdf->cam.roty);
	rotate_around_oz(&view_map[index], fdf->cam.rotz);
	if (fdf->cam.projection == ISO)
		iso(&view_map[index]);
	view_map[index].x += fdf->cam.x_offset;
	view_map[index].y += fdf->cam.y_offset;
}

void		model_to_view_map(t_fdf *fdf, t_point *view_map)
{
	int	index;

	index = 0;
	while (index < fdf->width * fdf->height)
	{
		projection(fdf, view_map, index);
		index++;
	}
}
