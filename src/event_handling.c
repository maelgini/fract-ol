/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:32:58 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/28 15:09:34 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 114)
		reset_fractal(fractal);
	else if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keysym == 65451)
	{
		fractal->max_iterations += 1;
		ft_printf("Max iterations: %d\n", fractal->max_iterations);
	}
	else if ((keysym == 65453) && (fractal->max_iterations > 1))
	{
		fractal->max_iterations -= 1;
		ft_printf("Max iterations: %d\n", fractal->max_iterations);
	}
	redraw_fractal(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = map((t_map){x, -2, 2, 0, WIDTH}) * fractal->zoom
		+ fractal->offset_x;
	mouse_y = map((t_map){y, 2, -2, 0, HEIGHT}) * fractal->zoom
		+ fractal->offset_y;
	ft_printf("%s%f%s%f\n\n", "Mouse X:\t", mouse_x, "\nMouse Y:\t", mouse_y);
	if (button == Button4)
	{
		fractal->zoom /= 2;
		fractal->offset_x = mouse_x + (fractal->offset_x - mouse_x) / 2;
		fractal->offset_y = mouse_y + (fractal->offset_y - mouse_y) / 2;
	}
	else if (button == Button5)
	{
		fractal->zoom *= 2;
		fractal->offset_x = mouse_x + (fractal->offset_x - mouse_x) * 2;
		fractal->offset_y = mouse_y + (fractal->offset_y - mouse_y) * 2;
	}
	redraw_fractal(fractal);
	return (0);
}
