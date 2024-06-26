/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_the_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:25:00 by oumimoun          #+#    #+#             */
/*   Updated: 2024/02/03 13:10:23 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_vars(t_fractal *fractal, char *set)
{
	if (!ft_strcmp(set, "M"))
	{
		fractal->start_x = -2;
		fractal->end_x = 0.9;
		fractal->start_y = -1.5;
		fractal->end_y = 1.5;
		fractal->zoom = 1.1;
	}
	else if (!ft_strcmp(set, "J"))
	{
		fractal->start_x = -2.5;
		fractal->end_x = 2.5;
		fractal->start_y = -2.5;
		fractal->end_y = 2.5;
		fractal->zoom = 1.1;
		fractal->c_real = 0.285;
		fractal->c_imag = 0.01;
	}
}

void	ft_setup_the_env(t_fractal *fractal, char *set)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		ft_print_error("Error");
	fractal->mlx_win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, set);
	if (!fractal->mlx_win)
		ft_print_error("Error");
	fractal->img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img)
		ft_print_error("Error");
	fractal->addr = mlx_get_data_addr(fractal->img, &(fractal->bpp),
			&(fractal->line_length), &(fractal->endian));
	fractal->set = set;
	ft_init_vars(fractal, set);
}
