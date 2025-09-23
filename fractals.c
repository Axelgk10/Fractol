#include "../fractol.h"

int	calculate_mandelbrot(t_complex c, int max_iter)
{
	int			i;
	t_complex	z;
	double		tmp;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < max_iter)
	{
		if (z.re * z.re + z.im * z.im > 4.0)
			break ;
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}

int	calculate_julia(t_complex z, t_complex c, int max_iter)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < max_iter)
	{
		if (z.re * z.re + z.im * z.im > 4.0)
			break ;
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}
