/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:23:07 by maelgini          #+#    #+#             */
/*   Updated: 2024/12/22 18:57:45 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	diff_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x - z2.x;
	result.y = z1.y - z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex	multiply_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x * z2.x - z1.y * z2.y;
	result.y = z1.x * z2.y + z1.y * z2.x;
	return (result);
}

t_complex	divide_complex(t_complex z1, t_complex z2)
{
	t_complex	result;
	double		denominator;

	denominator = z2.x * z2.x + z2.y * z2.y;
	result.x = (z1.x * z2.x + z1.y * z2.y) / denominator;
	result.y = (z1.y * z2.x - z1.x * z2.y) / denominator;
	return (result);
}
