#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
# include "./libft/libft.h"
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 100
# define ZOOM_FACTOR 1.1

# define KEY_ESC 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef struct s_complex
{
	double	re;
	double	im;
}t_complex;

typedef struct s_fractal
{
	//MLX connection
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	
	//Fractal configuration
	int		type;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iterations;

	//Julia Parameter
	t_complex julia_c;
	int		color_scheme;
} t_fractal;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

//Fractal types
# define MANDELBROT 1
# define JULIA 2

//Initialization
void	init_fractal(t_fractal *f, int type, double re, double im);
void	init_mlx(t_fractal *f);

//Events
void		key_press(mlx_key_data_t keydata, void *param);
void		mouse_hook(double xdelta, double ydelta, void *param);
void		close_window(void *param);
//Rendering
void	render_fractal(t_fractal *f);
void	my_mlx_pixel_out(t_fractal *f, int x, int y, int color);
//Fractals
int	calculate_mandelbrot(t_complex c, int max_iter);
int	calculate_julia(t_complex z, t_complex c, int max_iter);
//Colors
int			create_trgb(int t, int r, int g, int b);
int			get_color(int iterations, int max_iterations, int scheme);
//Math_utils
double	map(double value, t_range in, t_range out);
//Utils
int		ft_strcmp(const char *s1, const char *s2);
double	ft_atof(const char *str);
int		ft_isfloat(const char *str);
//Error_utils
void		display_help(void);
void		clean_exit(t_fractal *f, int exit_code);

#endif
