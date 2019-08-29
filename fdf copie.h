/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:37:07 by pthan             #+#    #+#             */
/*   Updated: 2019/08/27 17:41:32 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;	//Here you got an int * even though mlx_get_data_addr returns
						//a char *, i'll talk more about this in the .c file.
						////Here are the 3 "useless" variables. You can find more informations about these in the man page.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;
	//
	//			/*
	//			 Here is my main struct containing every variables needed by the MLX.
	//			  - mlx_ptr stores the return value of mlx_init
	//			   - win stores the return value of mlx_new_window
	//			    - img will store everything we need for the image part, the struct is described above.
	//			     */
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;
