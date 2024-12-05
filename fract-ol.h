/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:04:59 by maelgini          #+#    #+#             */
/*   Updated: 2024/12/05 21:43:51 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

//in case i would use this dumb exit() function
#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

//Window size (you can modify it :D)
#define WIDTH	800
#define	HEIGHT	800

//rgb palette (looks horrible)
#define BLACK       0x000000
#define WHITE       0xFFFFFF
#define RED         0xFF0000
#define GREEN       0x00FF00
#define BLUE        0x0000FF

//Fun palette
#define MAGENTA_BURST   0xFF00FF
#define LIME_SHOCK      0xCCFF00
#define NEON_ORANGE     0xFF6600
#define PSYCHEDELIC_PURPLE 0x660066
#define AQUA_DREAM      0x33CCCC
#define HOT_PINK        0xFF66B2
#define ELECTRIC_BLUE   0x0066FF
#define LAVA_RED        0xFF3300

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);

//Interactive events
int		close_handler(t_fractal *fractal);
int		key_handler(int keysym, t_fractal *fractal);
int		mouse_handler(int button, t_fractal *fractal);

//math utils
double  atodbl(char *s);
double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

//kick-off funcs
void    fractal_init(t_fractal *fractal);
void    fractal_render(t_fractal *fractal);

#endif