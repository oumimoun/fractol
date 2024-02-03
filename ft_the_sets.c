/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_sets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:31:34 by oumimoun          #+#    #+#             */
/*   Updated: 2024/02/03 13:11:37 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
	{
		fractal->start_x *= fractal->zoom;
		fractal->end_x *= fractal->zoom;
		fractal->start_y *= fractal->zoom;
		fractal->end_y *= fractal->zoom;
	}
	else if (mousecode == 5)
	{
		fractal->start_x /= fractal->zoom;
		fractal->end_x /= fractal->zoom;
		fractal->start_y /= fractal->zoom;
		fractal->end_y /= fractal->zoom;
	}
	if (!ft_strcmp(fractal->set, "J"))
		ft_julia(fractal);
	else
		ft_mandelbrot(fractal);
	return (0);
}

int	mouse_hook_julia(int x, int y, t_fractal *fractal)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		fractal->c_real = (double)x / WIDTH;
		fractal->c_imag = (double)y / HEIGHT;
		ft_julia(fractal);
	}
	return (0);
}

void	ft_mandelbrot(t_fractal *fractal)
{
	fractal->y_mlx = 0;
	while (fractal->y_mlx < HEIGHT)
	{
		fractal->x_mlx = 0;
		while (fractal->x_mlx < WIDTH)
		{
			ft_mapping_mandelbrot(fractal);
			fractal->color = ft_apply_the_set_mandelbrot(fractal);
			fractal->x_mlx++;
		}
		fractal->y_mlx++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win,
		fractal->img, 0, 0);
	mlx_mouse_hook(fractal->mlx_win, &mouse_hook, fractal);
	mlx_hook(fractal->mlx_win, 2, 0, &close_win, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, &close_win_button, fractal);
	mlx_loop(fractal->mlx_ptr);
}

void	ft_julia(t_fractal *fractal)
{
	fractal->y_mlx = 0;
	while (fractal->y_mlx < HEIGHT)
	{
		fractal->x_mlx = 0;
		while (fractal->x_mlx < WIDTH)
		{
			ft_mapping_julia(fractal);
			fractal->color = ft_apply_the_set_julia(fractal);
			fractal->x_mlx++;
		}
		fractal->y_mlx++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win,
		fractal->img, 0, 0);
	mlx_mouse_hook(fractal->mlx_win, &mouse_hook, fractal);
	mlx_hook(fractal->mlx_win, 6, 0, &mouse_hook_julia, fractal);
	mlx_hook(fractal->mlx_win, 2, 0, &close_win, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, &close_win_button, fractal);
	mlx_loop(fractal->mlx_ptr);
}
