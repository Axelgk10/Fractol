#include "../fractol.h"

void	init_fractal(t_fractal *f, int type, double re, double im)
{
	if (!f)
		return ;
	f->type = type;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iterations = MAX_ITERATIONS;
	f->julia_c.re = re;
	f->julia_c.im = im;
	f->color_scheme = 1;
	if (type == JULIA)
	{
		f->julia_c.re = re;
		f->julia_c.im = im;
	}
	else
	{
		f->julia_c.re = 0.0;
		f->julia_c.im = 0.0;
	}
}

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "fract'ol", false);
	if (!f->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		clean_exit (f, 1);
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
	{
		ft_printf("Error: Failed to create image\n");
		clean_exit(f, 1);
	}
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
	{
		ft_printf("Error: Failed to put image to window\n");
		clean_exit(f, 1);
	}
}
