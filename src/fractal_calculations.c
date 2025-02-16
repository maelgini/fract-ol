/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:05:38 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/14 18:40:43 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	mandelbrot_calc(t_complex z, t_complex c)
{
	return (sum_complex(square_complex(z), c));
}

t_complex	julia_calc(t_complex z, t_complex c)
{
	return (sum_complex(square_complex(z), c));
}

t_complex	burning_calc(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = -fabs(2 * z.x * z.y) + c.y;
	return (result);
}

/**
 * Newton fractal
 * zn+1 = zn - f(zn) / f'(zn)
 * f(z) = z^3 - 2z + 2
 * f'(z) =  
 * zn+1 = zn - (zn^3 - 2zn + 2) / (3zn^2 - 2)
 * 
 */

t_complex	newton_calc(t_complex z)
{
	t_complex	result;
	t_complex	f;
	t_complex	f_prime;

	f = z;
	f = square_complex(f);
	f = multiply_complex(f, z);
	f.x -= 2 * z.x - 2;
	f.y -= 2 * z.y;
	f_prime = square_complex(z);
	f_prime.x *= 3;
	f_prime.y *= 3;
	f_prime.x -= 2;
	result = diff_complex(z, divide_complex(f, f_prime));
	return (result);
}

t_complex	tricorn_calc(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = -2 * z.x * z.y + c.y;
	return (result);
}
/**
 * distance between two complex points
 * (x1 - x2)^2 + (y1 - y2)^2
 * distance root 1 = (z.x - r1.x)^2 + (z.y - r1.y)^2
 * distance root 2 = (z.x - r2.x)^2 + (z.y - r2.y)^2
 *  1. if distance root 1 < distance root 2
 *     return root 1    
 *   
  */