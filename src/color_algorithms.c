/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:56:20 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/28 14:34:21 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	interpolate_color(int color1, int color2, float t)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) * (1 - t) + ((color2 >> 16) & 0xFF) * t;
	g = ((color1 >> 8) & 0xFF) * (1 - t) + ((color2 >> 8) & 0xFF) * t;
	b = (color1 & 0xFF) * (1 - t) + (color2 & 0xFF) * t;
	return ((r << 16) | (g << 8) | b);
}

int	get_rainbow_color(float t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int i, int max_iterations, t_complex z)
{
	float	t;
	float	log_zn;
	float	nu;

	if (i == -1)
		return (BLACK);
	if (i == 0)
		return (BLACK);
	if (i < max_iterations)
	{
		log_zn = log(z.x * z.x + z.y * z.y) / 2;
		nu = log(log_zn / log(2)) / log(2);
		t = (i + 1 - nu) / max_iterations;
	}
	else
	{
		t = (float)i / max_iterations;
	}
	return (get_rainbow_color(t));
}

int	get_newton_color(t_complex z, t_complex *root, int i, int max_iterations)
{
	int		j;
	float	t;

	j = -1;
	while (j++ < 3)
	{
		if (distance(z, root[j]) < 0.001)
		{
			t = (float)i / max_iterations;
			if (j == 0)
				return (interpolate_color(GREEN, WHITE, t));
			else if (j == 1)
				return (interpolate_color(RED, WHITE, t));
			else
				return (interpolate_color(BLUE, WHITE, t));
		}
	}
	return (-1);
}
