/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:41:02 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/31 14:44:46 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iterations = 200;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->zoom = 1.000;
	if (ft_strncmp(fractal->name, "burningship", 11) == 0)
	{
		fractal->zoom = 0.050;
		fractal->offset_x = -1.700;
		fractal->offset_y = 0.030;
	}
	if (ft_strncmp(fractal->name, "newton", 6) == 0)
	{
		fractal->zoom = 32.000;
		fractal->max_iterations = 100;
	}
}

static void	init_mlx_and_img(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		print_err("ECONFAIL");
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
		print_err("EWINFAIL");
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
		print_err("EIMGNULL");
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (fractal->img.pixels_ptr == NULL)
		print_err("EPXLNULL");
}

void	fractal_init(t_fractal *fractal)
{
	init_mlx_and_img(fractal);
	mlx_hook(fractal->mlx_window,
		KeyPress,
		KeyPressMask,
		key_handler,
		fractal);
	mlx_mouse_hook(fractal->mlx_window,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		fractal);
	data_init(fractal);
}

void	redraw_fractal(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
	fractal_render(fractal);
}

void	reset_fractal(t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "burningship", 12) == 0)
	{
		fractal->zoom = 0.050;
		fractal->offset_x = -1.700;
		fractal->offset_y = 0.030;
	}
	else
	{
		fractal->zoom = 1.000;
		fractal->offset_x = 0;
		fractal->offset_y = 0;
		fractal->max_iterations = 1000;
		redraw_fractal(fractal);
	}
}
