#include "../fractol.h"

void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	mlx_put_pixel(f->img, x, y, color);
}

static t_complex	calculate_complex(t_fractal *f, int x, int y);
static void			render_pixel(t_fractal *f, int x, int y);

void	render_fractal(t_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(f, x, y);
			x++;
		}
		y++;
	}
}

static void	render_pixel(t_fractal *f, int x, int y)
{
	t_complex	c;
	int			iterations;

	iterations = 0;
	if (f->zoom == 0.0)
		f->zoom = 0.0001;
	c = calculate_complex(f, x, y);
	if (f->type == MANDELBROT)
		iterations = calculate_mandelbrot(c, f->max_iterations);
	else if (f->type == JULIA)
		iterations = calculate_julia(c, f->julia_c, f->max_iterations);
	my_mlx_pixel_put(f, x, y, get_color(iterations,
			f->max_iterations, f->color_scheme));
}

static t_complex	calculate_complex(t_fractal *f, int x, int y)
{
	t_complex	c;
	t_range		in_x;
	t_range		in_y;
	t_range		out_x;
	t_range		out_y;

	in_x = (t_range){0, WIDTH};
	in_y = (t_range){0, HEIGHT};
	out_x.min = -2.0 / f->zoom + f->offset_x;
	out_x.max = 2.0 / f->zoom + f->offset_x;
	out_y.min = -2.0 / f->zoom + f->offset_y;
	out_y.max = 2.0 / f->zoom + f->offset_y;
	c.re = map(x, in_x, out_x);
	c.im = map(y, in_y, out_y);
	return (c);
}
