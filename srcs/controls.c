/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:51:07 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:51:09 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key_macos.h"

void	flatten(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_1)
		fdf->cam.z_flattener -= 0.2;
	else if (key == MAIN_PAD_2)
		fdf->cam.z_flattener += 0.2;
	if (fdf->cam.z_flattener < 0.1)
		fdf->cam.z_flattener = 0.1;
	else if (fdf->cam.z_flattener > 10)
		fdf->cam.z_flattener = 10;
	draw(fdf);
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_3)
	{
		if (fdf->cam.zoom > 0)
			fdf->cam.zoom--;
	}
	if (key == MAIN_PAD_4)
	{
		if (fdf->cam.zoom < 2000000000)
			fdf->cam.zoom++;
	}
	draw(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_A)
		fdf->cam.rotz -= 0.05;
	else if (key == MAIN_PAD_D)
		fdf->cam.rotz += 0.05;
	else if (key == MAIN_PAD_S)
		fdf->cam.rotx -= 0.05;
	else if (key == MAIN_PAD_W)
		fdf->cam.rotx += 0.05;
	else if (key == MAIN_PAD_Q)
		fdf->cam.roty -= 0.05;
	else if (key == MAIN_PAD_E)
		fdf->cam.roty += 0.05;
	draw(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->cam.x_offset -= 5;
	else if (key == ARROW_RIGHT)
		fdf->cam.x_offset += 5;
	else if (key == ARROW_UP)
		fdf->cam.y_offset -= 5;
	else if (key == ARROW_DOWN)
		fdf->cam.y_offset += 5;
	draw(fdf);
}
