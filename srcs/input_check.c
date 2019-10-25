/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:52:29 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:52:31 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

int		get_nbr_per_line(char *str)
{
	unsigned int	nbr_per_line;

	nbr_per_line = 0;
	while (*str)
	{
		if (*str != ' ')
		{
			while (*str && *str != ' ')
				str++;
			nbr_per_line++;
		}
		else
			str++;
	}
	return (nbr_per_line);
}

int		get_dimensions(t_fdf *fdf)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	while (++i && (ret = get_next_line(fdf->fd, &line) > 0))
	{
		if (i == 1)
			fdf->width = get_nbr_per_line(line);
		else if (get_nbr_per_line(line) != fdf->width)
			close(fdf->fd);
		fdf->height++;
	}
	if (ret <= 0)
		close(fdf->fd);
	if (!ret)
		ft_strdel(&line);
	if (ret < 0 || (!ret && !fdf->width && !fdf->height))
		return (0);
	else
		return (1);
}

int		get_file(t_fdf *fdf)
{
	int		i;
	int		ret;
	char	*line;

	if ((fdf->fd = open(fdf->file, O_RDONLY)) < 0)
	{
		ft_printf("usage error\n");
		return (0);
	}
	i = 0;
	while ((ret = get_next_line(fdf->fd, &line) > 0)
	&& (fdf->map[i] = create_tab(fdf, line)))
		i++;
	ft_strdel(&line);
	close(fdf->fd);
	if (i == fdf->height && !ret)
		return (1);
	else
		return (0);
}

void	initialize_cam(t_fdf *fdf)
{
	fdf->cam.projection = ISO;
	fdf->cam.zoom =
		FT_MIN((WIN_WIDTH / fdf->width) / 2, (WIN_HEIGHT / fdf->height) / 2);
	fdf->cam.rotx = 0;
	fdf->cam.roty = 0;
	fdf->cam.rotz = 0;
	fdf->cam.z_flattener = 5;
	fdf->cam.x_offset = (3 * WIN_WIDTH / 7);
	fdf->cam.y_offset = WIN_HEIGHT / 4;
}

int		parse_file(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
	if (!get_dimensions(fdf))
	{
		ft_printf("wrong file format\n");
		return (0);
	}
	if (!(fdf->map =
			(t_point **)ft_memalloc((fdf->height + 1) * sizeof(t_point *))))
		return (0);
	if (!get_file(fdf))
	{
		ft_printf("parsing problem\n");
		return (free_map(fdf));
	}
	initialize_cam(fdf);
	return (1);
}
