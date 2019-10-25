/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 02:52:37 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 02:52:38 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key_macos.h"

void	ft_display_window
	(t_mlx *mlx, char *title, int img_width, int img_height)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, title);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, img_width, img_height);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr,
		&(mlx->img.bpp), &(mlx->img.size_l), &(mlx->img.endian));
}

int		close_fdf(void *param)
{
	free_map((t_fdf *)param);
	(void)param;
	exit(0);
}

int		key_press(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == MAIN_PAD_1 || key == MAIN_PAD_2)
		flatten(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
	|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
	else if (key == MAIN_PAD_A || key == MAIN_PAD_W
	|| key == MAIN_PAD_D || key == MAIN_PAD_S
	|| key == MAIN_PAD_Q || key == MAIN_PAD_E)
		rotate(key, fdf);
	else if (key == MAIN_PAD_3 || key == MAIN_PAD_4)
		zoom(key, fdf);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_LEFT_BUTTON)
		fdf->cam.projection = ISO;
	else if (button == MOUSE_RIGHT_BUTTON)
		fdf->cam.projection = PARALLEL;
	else if (button == MOUSE_SCROLL_DOWN && fdf->cam.zoom > 1)
		fdf->cam.zoom--;
	else if (button == MOUSE_SCROLL_UP && fdf->cam.zoom < 100000)
		fdf->cam.zoom++;
	draw(fdf);
	return (0);
}

void	setup_controls(t_fdf *fdf)
{
	mlx_hook(fdf->mlx.win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->mlx.win_ptr, 17, 0, close_fdf, fdf);
	mlx_hook(fdf->mlx.win_ptr, 4, 0, mouse_press, fdf);
}
