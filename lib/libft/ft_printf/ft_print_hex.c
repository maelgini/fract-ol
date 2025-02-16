/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:34:08 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/25 18:53:21 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int num, int size, char format)
{
	char			*hex_digits;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		size = ft_putnbr_hex(num / 16, size, format);
	ft_putchar(hex_digits[num % 16]);
	size++;
	return (size);
}

int	ft_putstr_hex(void *ptr)
{
	unsigned long long	addr;
	char				*hex;
	int					len;
	char				hex_str[16];
	int					i;

	addr = (unsigned long long)ptr;
	hex = "0123456789abcdef";
	len = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	i = 15;
	len += write(1, "0x", 2);
	if (addr == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	while (addr > 0)
	{
		hex_str[i--] = hex[addr % 16];
		addr /= 16;
	}
	len += write(1, &hex_str[i + 1], 15 - i);
	return (len);
}
