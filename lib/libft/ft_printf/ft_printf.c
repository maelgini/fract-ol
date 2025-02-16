/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:33:40 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/25 19:21:48 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_putstr_hex(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int), 0);
	else if (format == 'u')
		print_len += ft_unsigned_putnbr(va_arg(args, unsigned int), 0);
	else if (format == 'x' || format == 'X')
		print_len += ft_putnbr_hex(va_arg(args, unsigned int), 0, format);
	else if (format == 'f')
		print_len += ft_putfloat(va_arg(args, double), 0);
	else
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_len;
	int		ret;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = ft_format(args, format[i + 1]);
			total_len += ret;
			i++;
		}
		else
			total_len += write(1, &format[i], 1);
		i++;
	}
	return (va_end(args), total_len);
}
