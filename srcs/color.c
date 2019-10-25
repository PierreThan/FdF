/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:51:16 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:51:18 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		percentag(int p0, int p1, int curr)
{
	double	placement;
	double	distance;

	placement = curr - p0;
	distance = p1 - p0;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int	get_light(int p0, int p1, double percentage)
{
	return ((int)((1 - percentage) * p0 + percentage * p1));
}

int			get_color(t_point curr, t_point p0, t_point p1, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (curr.color == p1.color || p0.color == p1.color)
		return (p1.color);
	if (delta.x > delta.y)
		percentage = percentag(p0.x, p1.x, curr.x);
	else
		percentage = percentag(p0.y, p1.y, curr.y);
	red =
	get_light((p0.color >> 16) & 0xFF, (p1.color >> 16) & 0xFF, percentage);
	green =
	get_light((p0.color >> 8) & 0xFF, (p1.color >> 8) & 0xFF, percentage);
	blue =
	get_light(p0.color & 0xFF, p1.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
