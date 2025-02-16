/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:56:50 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/27 18:36:24 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

void	ft_putchar(char c);
int		ft_putnbr_hex(unsigned int n, int size, char format);
int		ft_putstr_hex(void *ptr);
int		ft_format(va_list args, const char format);
int		ft_char(char c);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int nb, int size);
int		ft_putstr(char *str);
int		ft_unsigned_putnbr(unsigned int u, int size);
int		ft_putfloat(double n, int size);
int		ft_putfloat_frac(double frac_part, int precision);
int		get_num_size(int n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif