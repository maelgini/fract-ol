/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:10:07 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/31 13:39:50 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	print_err(const char *errcode)
{
	if (!ft_strncmp(errcode, "ECONFAIL", 8))
		ft_putstr_fd("Error: Failed to initialize MLX connection\n", 2);
	else if (!ft_strncmp(errcode, "EWINFAIL", 8))
		ft_putstr_fd("Error: Failed to create MLX window\n", 2);
	else if (!ft_strncmp(errcode, "EIMGNULL", 8))
		ft_putstr_fd("Error: Failed to create MLX image\n", 2);
	else if (!ft_strncmp(errcode, "EPXLNULL", 8))
		ft_putstr_fd("Error: Failed to get image data address\n", 2);
	else if (!ft_strncmp(errcode, "EARGERR", 7))
		ft_putstr_fd(EARGERR, 2);
	else
		ft_putstr_fd(ERR_MSG, 2);
	exit(EXIT_FAILURE);
	return (0);
}

void	ft_printf_commands(void)
{
	ft_printf("Commands:\n");
	ft_printf("Zoom in: Mouse wheel up\n");
	ft_printf("Zoom out: Mouse wheel down\n");
	ft_printf("Move: Arrow keys\n");
	ft_printf("Exit: ESC\n");
	ft_printf("Increase iterations: Num +\n");
	ft_printf("Decrease iterations: Num -\n");
}

double	ft_atod(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
