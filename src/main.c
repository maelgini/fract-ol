/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:58:51 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/31 13:59:03 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 11)
				|| !ft_strncmp(av[1], "newton", 7)
				|| !ft_strncmp(av[1], "tricorn", 8)
				|| !ft_strncmp(av[1], "burningship", 12)))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atod(av[2]);
			fractal.julia_y = ft_atod(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		ft_printf_commands();
		mlx_hook(fractal.mlx_window, KeyPress,
			KeyPressMask, key_handler, &fractal);
		mlx_mouse_hook(fractal.mlx_window, mouse_handler, &fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		print_err("EARGERR");
}
