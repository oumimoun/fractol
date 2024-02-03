/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 05:28:25 by oumimoun          #+#    #+#             */
/*   Updated: 2024/02/03 13:21:43 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	iteration_to_color(t_fractal *fractal)
{
	int	red;
	int	green;
	int	blue;

	if (fractal->iterator == -1)
		my_mlx_pixel_put(fractal, fractal->x_mlx, fractal->y_mlx, 0x000000);
	else
	{
		red = (fractal->iterator * 3) % 256;
		green = (fractal->iterator * 9) % 256;
		blue = (fractal->iterator * 12) % 256;
		fractal->color = (red << 16) | (green << 8) | blue;
		my_mlx_pixel_put(fractal, fractal->x_mlx,
			fractal->y_mlx, fractal->color);
	}
}

int	ft_apply_the_set_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0.0;
	fractal->y = 0.0;
	fractal->iterator = 0;
	while (fractal->iterator < MAX_ITER)
	{
		fractal->x_temp = (fractal->x * fractal->x) - (fractal->y * fractal->y)
			+ fractal->c_real;
		fractal->y_temp = (2 * fractal->x * fractal->y) + fractal->c_imag;
		fractal->x = fractal->x_temp;
		fractal->y = fractal->y_temp;
		fractal->iterator++;
		if (fractal->x * fractal->x + fractal->y * fractal->y > 20)
			break ;
	}
	if (fractal->iterator == MAX_ITER)
		fractal->iterator = -1;
	iteration_to_color(fractal);
	return (fractal->iterator);
}

int	ft_apply_the_set_julia(t_fractal *fractal)
{
	fractal->iterator = 0;
	while (fractal->iterator < MAX_ITER)
	{
		fractal->x_temp = fractal->x * fractal->x - fractal->y * fractal->y
			+ fractal->c_real;
		fractal->y_temp = 2 * fractal->x * fractal->y + fractal->c_imag;
		fractal->x = fractal->x_temp;
		fractal->y = fractal->y_temp;
		fractal->iterator++;
		if (fractal->x * fractal->x + fractal->y * fractal->y > 20)
			break ;
	}
	if (fractal->iterator == MAX_ITER)
		fractal->iterator = -1;
	iteration_to_color(fractal);
	return (fractal->iterator);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "M"))
		{
			ft_setup_the_env(&fractal, argv[1]);
			ft_mandelbrot(&fractal);
		}
		else if (!ft_strcmp(argv[1], "J"))
		{
			ft_setup_the_env(&fractal, argv[1]);
			ft_julia(&fractal);
		}
	}
	if (argc == 4 && !ft_strcmp(argv[1], "J"))
	{
		if (ft_arg_is_valid(argv[2]) && ft_arg_is_valid(argv[3]))
			ft_parce_args(&fractal, argv[1], argv[2], argv[3]);
	}
	else
		ft_print_error("Try using ./fractol <M or J>");
	return (0);
}
