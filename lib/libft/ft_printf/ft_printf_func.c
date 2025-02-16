/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:54:11 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/25 20:32:24 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int size)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		size++;
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		size = ft_putnbr(n / 10, size);
		n %= 10;
	}
	ft_putchar(n + '0');
	size++;
	return (size);
}

int	ft_unsigned_putnbr(unsigned int u, int size)
{
	size = 0;
	if (u > 9)
	{
		size = ft_unsigned_putnbr(u / 10, size);
		u %= 10;
	}
	ft_putchar(u + '0');
	size++;
	return (size);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_putfloat_frac(double frac_part, int precision)
{
	int		frac_as_int;
	int		count;

	frac_as_int = (int)(frac_part * 1000000);
	count = 0;
	write(1, ".", 1);
	count++;
	while (precision > 1 && frac_as_int < 100000)
	{
		write(1, "0", 1);
		count++;
		precision--;
		frac_as_int *= 10;
	}
	count += ft_putnbr(frac_as_int, 0);
	return (count);
}

int	ft_putfloat(double n, int size)
{
	int		int_part;
	double	frac_part;
	int		count;
	int		precision;

	precision = 6;
	int_part = (int)n;
	frac_part = n - int_part;
	if (frac_part < 0)
		frac_part = -frac_part;
	if (n < 0 && int_part == 0)
	{
		ft_putchar('-');
		size++;
	}
	count = ft_putnbr(int_part, size);
	count += ft_putfloat_frac(frac_part, precision);
	return (count);
}
