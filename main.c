/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:58:51 by maelgini          #+#    #+#             */
/*   Updated: 2024/12/05 14:10:59 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (((2 == ac) && (!ft_strncmp(av[1], "mandelbrot", 10))) || ((4 == ac) && (!ft_strncmp(av[1], "julia", 5))))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}