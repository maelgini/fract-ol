/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:04:59 by maelgini          #+#    #+#             */
/*   Updated: 2025/01/31 13:53:43 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>

# define EARGERR "\n====================USAGE:=====================\n./fractol \
mandelbrot/burningship/tricorn/newton \
	\n./fractol \
julia <value_1> <value_2>\n===============================================\n"
# define ERR_MSG "Error\n"
# define WIDTH	600
# define HEIGHT 600

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define PURPLE		0x800080
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char				*name;
	void				*mlx_connection;
	void				*mlx_window;
	double				escape_value;
	int					max_iterations;
	double				offset_x;
	double				offset_y;
	double				zoom;
	double				julia_x;
	double				julia_y;
	double				min_r;
	double				max_r;
	double				min_i;
	double				max_i;
	int					color_scheme;
	t_img				img;
	struct s_complex	(*get_set)(t_complex z, t_complex c);
	struct s_complex	(*get_set2)(t_complex z);
}	t_fractal;

//forbidden multi-threading struct example
// typedef struct s_thread_data
// {
// 	t_fractal	*fractal;
// 	int			start_y;
// 	int			end_y;
// }				t_thread_data;

typedef struct s_map
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}	t_map;

typedef struct s_pixel_params
{
	t_fractal	*fractal;
	int			x;
	int			y;
	double		zoom;
	double		shift_x;
	double		shift_y;
}	t_pixel_params;

typedef struct s_handle_pixel
{
	t_fractal	*fractal;
	int			x;
	int			y;
	double		zoom;
	double		shift_x;
	double		shift_y;
}	t_handle_pixel;

//see complex_op.c
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	diff_complex(t_complex z1, t_complex z2);
t_complex	multiply_complex(t_complex z1, t_complex z2);
t_complex	divide_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//see fractal_calc.c
t_complex	mandelbrot_calc(t_complex z, t_complex c);
t_complex	julia_calc(t_complex z, t_complex c);
t_complex	burning_calc(t_complex z, t_complex c);
t_complex	tricorn_calc(t_complex z, t_complex c);
t_complex	newton_calc(t_complex z);

int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			additionnal_events(int keysym, t_fractal *fractal);

int			is_in_main_bulbs(t_complex c, const char *fractal_name);
double		distance(t_complex z, t_complex r);
double		map(t_map map);

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		redraw_fractal(t_fractal *fractal);
void		reset_fractal(t_fractal *fractal);

//see color_algorithms.c
int			get_newton_color(t_complex z, t_complex *root, int i,
				int max_iterations);
int			get_color(int i, int max_iterations, t_complex z);
int			interpolate_color(int color1, int color2, float t);
int			get_rainbow_color(float t);

//see complex_init.c
void		init_complex(t_complex *z, t_complex *c, t_fractal *fractal);
void		init_complex_bonus(t_complex *z, t_complex *c, t_fractal *fractal);

//see other.c
double		ft_atod(char *s);
int			print_err(const char *errcode);
void		ft_printf_commands(void);

#endif