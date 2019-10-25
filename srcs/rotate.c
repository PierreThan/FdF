/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:52:47 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:52:49 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"
#include <math.h>

void	rotate_around_ox(t_point *point, double theta)
{
	int tmp_y;

	tmp_y = point->y;
	point->y = tmp_y * cos(theta) + point->z * sin(theta);
	point->z = point->z * cos(theta) - tmp_y * sin(theta);
}

void	rotate_around_oy(t_point *point, double theta)
{
	int tmp_x;

	tmp_x = point->x;
	point->x = tmp_x * cos(theta) + point->z * sin(theta);
	point->z = point->z * cos(theta) - tmp_x * sin(theta);
}

void	rotate_around_oz(t_point *point, double theta)
{
	int tmp_y;

	tmp_y = point->y;
	point->y = tmp_y * cos(theta) + point->x * sin(theta);
	point->x = point->x * cos(theta) - tmp_y * sin(theta);
}
