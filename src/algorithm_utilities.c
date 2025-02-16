/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:11:13 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/25 16:52:14 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	map(t_map map)
{
	return ((map.new_max - map.new_min) * (map.unscaled_num - map.old_min)
		/ (map.old_max - map.old_min) + map.new_min);
}

double	distance(t_complex z, t_complex r)
{
	return ((z.x - r.x) * (z.x - r.x) + (z.y - r.y) * (z.y - r.y));
}

int	is_in_main_bulbs(t_complex c, const char *fractal_name)
{
	double	q;

	if (!ft_strncmp(fractal_name, "mandelbrot", 11))
	{
		q = (c.x - 0.25) * (c.x - 0.25) + c.y * c.y;
		if (q * (q + (c.x - 0.25)) <= 0.25 * c.y * c.y)
			return (1);
		if ((c.x + 1) * (c.x + 1) + c.y * c.y <= 0.0625)
			return (1);
	}
	return (0);
}
