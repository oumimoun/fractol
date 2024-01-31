/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_sets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:31:34 by oumimoun          #+#    #+#             */
/*   Updated: 2024/01/31 15:45:02 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
    if (mousecode == 4)
    {
        fractal->start_x *=  fractal->zoom;
        fractal->end_x *= fractal->zoom;
        fractal->start_y *=  fractal->zoom;
        fractal->end_y *=  fractal->zoom;
    }
    else if (mousecode == 5)
    {
        fractal->start_x /=  fractal->zoom;   
        fractal->end_x /= fractal->zoom;
        fractal->start_y /=  fractal->zoom;
        fractal->end_y /=  fractal->zoom;
    }

    ft_mandelbrot(fractal);

    return (0);
}



void ft_mandelbrot(t_fractal *fractal)
{
    fractal->y_real = 0;
    while (fractal->y_real < HEIGHT)
    {
        fractal->x_real = 0;
        while (fractal->x_real < WIDTH)
        {
            ft_mapping_mandelbrot(fractal);
            fractal->color = ft_apply_the_set_mandelbrot(fractal);
            // 
            fractal->x_real++;
        }
        fractal->y_real++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->img, 0, 0);
    mlx_mouse_hook(fractal->mlx_win, &mouse_hook, fractal);
    mlx_loop(fractal->mlx_ptr);
}

void ft_julia(t_fractal *fractal)
{
    fractal->y_real = 0;
    while (fractal->y_real < HEIGHT)
    {
        fractal->x_real = 0;
        while (fractal->x_real < WIDTH)
        {
            ft_mapping_julia(fractal);
            fractal->color = ft_apply_the_set_julia(fractal);
            // 
            fractal->x_real++;
        }
        fractal->y_real++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win, fractal->img, 0, 0);
    mlx_loop(fractal->mlx_ptr);
}

