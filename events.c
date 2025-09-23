#include "../fractol.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		clean_exit(f, 0);
	else if (keydata.key == MLX_KEY_C)
		f->color_scheme = (f->color_scheme % 3) + 1;
	else if (keydata.key == MLX_KEY_R)
		init_fractal(f, f->type, f->julia_c.re, f->julia_c.im);
	else if (keydata.key == MLX_KEY_LEFT)
		f->offset_x -= 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_RIGHT)
		f->offset_x += 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_UP)
		f->offset_y -= 0.1 / f->zoom;
	else if (keydata.key == MLX_KEY_DOWN)
		f->offset_y += 0.1 / f->zoom;
	else
		return ;
	render_fractal(f);
}

void	mouse_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	(void)xdelta;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	render_fractal(f);
}

void	close_window(void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	clean_exit (f, 0);
}
