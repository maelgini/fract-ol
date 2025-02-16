/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:28:54 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/14 19:06:55 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_complex(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->y = z->y;
		fractal->get_set = mandelbrot_calc;
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
		fractal->get_set = julia_calc;
	}
}

void	init_complex_bonus(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "burningship", 11))
	{
		c->x = z->x;
		c->y = z->y;
		fractal->get_set = burning_calc;
	}
	else if (!ft_strncmp(fractal->name, "tricorn", 7))
	{
		c->x = z->x;
		c->y = z->y;
		fractal->get_set = tricorn_calc;
	}
	else if (!ft_strncmp(fractal->name, "newton", 6))
	{
		c->x = z->x;
		c->y = z->y;
		fractal->get_set2 = newton_calc;
	}
}
