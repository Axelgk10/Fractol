#include "../fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isfloat(const char *str)
{
	int	i;
	int	has_dot;

	if (!str || !*str)
		return (0);
	i = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static double	process_integer_part(const char *str, int *i, int *sign)
{
	double	result;

	result = 0.0;
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
		(*i)++;
	if (str[*i] == '-')
		*sign = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	process_fractional_part(const char *str, int *i,
						double integer_part)
{
	double	result;
	double	fraction;

	result = integer_part;
	if (str[*i] == '.')
	{
		(*i)++;
		fraction = 0.1;
		while (ft_isdigit(str[*i]))
		{
			result += (str[*i] - '0') * fraction;
			fraction *= 0.1;
			(*i)++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	res;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	res = process_integer_part(str, &i, &sign);
	res = process_fractional_part(str, &i, res);
	return (res * sign);
}
