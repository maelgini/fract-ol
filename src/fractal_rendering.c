/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:27:13 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/28 14:37:12 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static inline void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	pixel_newton(int x, int y, t_fractal *fractal)
{
	t_complex			z;
	int					i;
	int					color;
	static t_complex	root[3] = {
		(t_complex){-1.76929, 0},
		(t_complex){0.88465, 0.58974},
		(t_complex){0.88465, -0.58974}};

	i = 0;
	z.x = (map((t_map){x, -2, 2, 0, WIDTH})
			* fractal->zoom) + fractal->offset_x;
	z.y = (map((t_map){y, +2, -2, 0, HEIGHT})
			* fractal->zoom) + fractal->offset_y;
	while (i++ < fractal->max_iterations)
	{
		z = newton_calc(z);
		color = get_newton_color(z, root, i, fractal->max_iterations);
		if (color != -1)
		{
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
	}
	pixel_put(x, y, &fractal->img, BLACK);
}

static void	handle_iterations(t_pixel_params params, t_complex z, t_complex c)
{
	int	i;
	int	color;

	i = 0;
	while (i < params.fractal->max_iterations)
	{
		z = params.fractal->get_set(z, c);
		if ((z.x * z.x) + (z.y * z.y) > params.fractal->escape_value
			* params.fractal->escape_value)
		{
			color = get_color(i, params.fractal->max_iterations, z);
			pixel_put(params.x, params.y, &params.fractal->img, color);
			return ;
		}
		i++;
	}
	pixel_put(params.x, params.y, &params.fractal->img, BLACK);
}

static void	handle_pixel(t_pixel_params params)
{
	t_complex	z;
	t_complex	c;

	if (ft_strncmp(params.fractal->name, "newton", 6) == 0)
	{
		pixel_newton(params.x, params.y, params.fractal);
		return ;
	}
	z.x = (map((t_map){params.x, -2, 2, 0, WIDTH})
			* params.zoom) + params.shift_x;
	z.y = (map((t_map){params.y, 2, -2, 0, HEIGHT})
			* params.zoom) + params.shift_y;
	init_complex(&z, &c, params.fractal);
	init_complex_bonus(&z, &c, params.fractal);
	if (is_in_main_bulbs(c, params.fractal->name))
	{
		pixel_put(params.x, params.y, &params.fractal->img, BLACK);
		return ;
	}
	handle_iterations(params, z, c);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel((t_pixel_params){fractal, x, y, fractal->zoom,
				fractal->offset_x,
				fractal->offset_y});
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
