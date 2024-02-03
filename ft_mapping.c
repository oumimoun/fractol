/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:30:20 by oumimoun          #+#    #+#             */
/*   Updated: 2024/02/03 13:05:12 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mapping_mandelbrot(t_fractal *fractal)
{
	fractal->x = fractal->x_mlx * ((fractal->end_x - fractal->start_x) / WIDTH)
		+ fractal->start_x;
	fractal->y = fractal->y_mlx * ((fractal->end_y - fractal->start_y) / HEIGHT)
		+ fractal->start_y;
	fractal->c_real = fractal->x;
	fractal->c_imag = fractal->y;
}

void	ft_mapping_julia(t_fractal *fractal)
{
	fractal->x = fractal->x_mlx * ((fractal->end_x - fractal->start_x) / WIDTH)
		+ fractal->start_x;
	fractal->y = fractal->y_mlx * ((fractal->end_y - fractal->start_y) / HEIGHT)
		+ fractal->start_y;
}
