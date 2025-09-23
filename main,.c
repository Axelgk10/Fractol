#include "../fractol.h"

static int	is_valid_julia_params(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (!ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
		return (0);
	return (1);
}

static void	parse_arguments(int argc, char **argv, t_fractal *f)
{
	if (argc < 2)
		display_help();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		init_fractal(f, MANDELBROT, 0, 0);
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (!is_valid_julia_params(argc, argv))
		{
			ft_printf("Error: Julia requiere dos parámetros numéricos\n");
			display_help();
		}
		init_fractal(f, JULIA, ft_atof(argv[2]), ft_atof(argv[3]));
	}
	else
		display_help();
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	ft_memset(&f, 0, sizeof(t_fractal));
	parse_arguments(argc, argv, &f);
	init_mlx(&f);
	render_fractal(&f);
	if (f.mlx)
	{
		mlx_key_hook(f.mlx, &key_press, &f);
		mlx_scroll_hook(f.mlx, &mouse_hook, &f);
		mlx_close_hook(f.mlx, &close_window, &f);
		mlx_loop(f.mlx);
	}
	clean_exit(&f, 0);
	return (0);
}
