#include "../fractol.h"

double	map(double value, t_range in, t_range out)
{
	return (out.min + (out.max - out.min)
		* (value - in.min) / (in.max - in.min));
}
