/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 05:28:25 by oumimoun          #+#    #+#             */
/*   Updated: 2024/01/31 16:00:44 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}


void iteration_to_color(t_fractal *fractal)
{
    int x = fractal->x_real;
    int y = fractal->y_real;

    if (fractal->iterator == -1)
        my_mlx_pixel_put(fractal, x, y, 0x000000);
    else
    {
        int red = (fractal->iterator * 3) % 256;
        
        int green = (fractal->iterator * 9) % 256;
        
        int blue = (fractal->iterator * 12) % 256;

        int color = (red << 16) | (green << 8) | blue;
        
        my_mlx_pixel_put(fractal, x, y, color);
    }
}

int ft_apply_the_set_mandelbrot(t_fractal *fractal)
{
    fractal->iterator = 0;
    while (fractal->iterator < MAX_ITER)
    {
        fractal->xtemp = (fractal->x * fractal->x) - (fractal->y * fractal->y) + fractal->c_real;
        fractal->ytemp = (2 * fractal->x * fractal->y) + fractal->c_imag;
        fractal->x = fractal->xtemp;
        fractal->y = fractal->ytemp;
        fractal->iterator++;
        if (fractal->x * fractal->x + fractal->y * fractal->y > 20)
            break;
    }
    if (fractal->iterator == MAX_ITER)
        fractal->iterator = -1;
    iteration_to_color(fractal);
    return (fractal->iterator);
}

int ft_apply_the_set_julia(t_fractal *fractal)
{
    fractal->iterator = 0;
    while (fractal->iterator < MAX_ITER)
    {
        fractal->xtemp = fractal->x * fractal->x - fractal->y * fractal->y + fractal->c_real;
        fractal->ytemp = 2 * fractal->x * fractal->y + fractal->c_imag;
        fractal->x = fractal->xtemp;
        fractal->y = fractal->ytemp;
        fractal->iterator++;
        if (fractal->x * fractal->x + fractal->y * fractal->y > 5)
            break;
    }
    if (fractal->iterator == MAX_ITER)
        fractal->iterator = -1;
    iteration_to_color(fractal);
    return (fractal->iterator);
}



int main(int argc, char **argv)
{
    t_fractal fractal;

    // atexit(leak);
    if (argc == 2)
    {
        if (!ft_strcmp(argv[1], "M"))
        {
            ft_setup_the_env(&fractal, argv[1]);
            ft_mandelbrot(&fractal);
            //
        }
        else if (!ft_strcmp(argv[1], "J"))
        {
            ft_setup_the_env(&fractal, argv[1]);

            ft_julia(&fractal);
        }
    }
    else if (argc == 4 && !ft_strcmp(argv[1], "J"))
    {
        // julia
        if (ft_arg_is_valid(argv[2]) && ft_arg_is_valid(argv[3]))
        {
            // ft_juilia with args;
            // return(0);
        }
    }
    else
    {
        write(2, "\033[33m", 5);
        write(2, "please consider using ./fractol <'M' or 'J'>\n", 46);
        write(2, "\033[0m", 5);
        exit(1);
    }
    return (0);
}
