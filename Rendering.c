#include "../fractol.h"

void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
    char    *dst;

    dst = f->addr + (y * f->line_length + x * (f->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	render_fractal(t_fractal *f)
{
    int x;
    int y;
    int iterations;
    t_complex   c;
    t_complex   z;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c.re = map(x, 0, WIDTH, -2.0 / f->zoom + f->offset_x, 2.0 / f->zoom + f->offset_x);
            c.im = map(y, 0, HEIGTH, -2.0 / f->zoom + f->offset_y, 2.0 / f->zoom + f->offst_y);
            if (f->type == MANDELBROT)
                iterations = claculate_mandelbrot(c, f->max_iterations);
            else if (f->type == JULIA)
                iterations = calculate_julia(c, f->julia_c, f->max_iterations);
            my_mlx_pixel_put(f, x, y,get_color(iterations, f->max_iterations, f->color_scheme));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
