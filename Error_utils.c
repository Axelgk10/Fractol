#include "../fractol.h"

void	display_help(void)
{
	ft_printf("Usage: ./fractol <fractal_type> [parameters]\n");
	ft_printf("Available fractals:\n");
	ft_printf("  mandelbrot\n");
	ft_printf("  julia <real> <imaginary>\n");
	ft_printf("Examples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia -0.7 0.27\n");
	exit(0);
}

void	clean_exit(t_fractal *f, int exit_code)
{
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
	{
		mlx_terminate(f->mlx);
	}
	exit(exit_code);
}
