#include "fract-ol.h"
#include "minilibx-linux/mlx.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 0xff51)
		fractal->shift_x += 1;
	else if (keysym == 0xff52)
		fractal->shift_y -= 1;
	else if (keysym == 0xff53)
		fractal->shift_x -= 1;
	else if (keysym == 0xff54)
		fractal->shift_y += 1;
	return (0);
}

int	mouse_handler(int button, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 0.95;
	if (button == Button4)
		fractal->zoom *= 1.05;
	return (0);
}