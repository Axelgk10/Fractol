#include "../fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	calculate_color_scheme(double t, int iterations, int scheme)
{
	int		r;
	int		g;
	int		b;

	if (scheme == 1)
	{
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (scheme == 2)
	{
		r = (int)(sin(0.3 * iterations + 0) * 127 + 128);
		g = (int)(sin(0.3 * iterations + 2) * 127 + 128);
		b = (int)(sin(0.3 * iterations + 4) * 127 + 128);
	}
	else
	{
		r = (int)(t * 255);
		g = (int)(t * 255);
		b = (int)(t * 255);
	}
	return (create_trgb(0, t, g, b));
}

int	get_color(int iterations, int max_iterations, int scheme)
{
	double	t;

	if (iterations == max_iterations)
		return (create_trgb(0, 0, 0, 0));
	t = (double)iterations / max_iterations;
	return (calculate_color_scheme(t, iterations, scheme));
}
