/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:52:10 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:52:13 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

static void		get_color_first(char *str, t_point *point)
{
	char *tmp;

	if ((tmp = ft_strchr(str, ',')))
		point->color = ft_atoi_base((tmp + 3), 16);
	else
		point->color = 16777215;
}

unsigned int	add_info(t_fdf *fdf, char *ptr, t_point *map)
{
	char			*tmp;
	unsigned int	index;

	index = 0;
	while (ptr[index] != ' ' && ptr[index])
		index++;
	if ((tmp = ft_strsub(ptr, 0, index)))
	{
		map->z = ft_atoi(tmp);
		get_color_first(tmp, map);
		free(tmp);
		fdf->max.z = (map->z > fdf->max.z ? map->z : fdf->max.z);
		while (ptr[index] == ' ' && ptr[index])
			index++;
	}
	return (index);
}

t_point			*create_tab(t_fdf *fdf, char *str)
{
	char	*ptr;
	int		i;
	t_point	*map;

	if (!str)
		return (NULL);
	ptr = str;
	if (!(map = (t_point *)ft_memalloc(fdf->width * sizeof(t_point))))
		return (0);
	while (*ptr && *ptr == ' ')
		ptr++;
	i = 0;
	while (fdf->width > i)
	{
		ptr += add_info(fdf, ptr, map + i);
		i++;
	}
	return (map);
}

void			show_tab(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->map[i][j].z < 10)
				ft_putchar(' ');
			ft_putnbr(fdf->map[i][j].z);
			if (fdf->map[i][j].color != 0xFFFFFF)
			{
				ft_putstr(",0x");
				ft_putnbr(fdf->map[i][j].color);
			}
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
