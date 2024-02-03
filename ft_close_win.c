/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:50:59 by oumimoun          #+#    #+#             */
/*   Updated: 2024/02/03 13:04:23 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
		exit(0);
	}
	return (0);
}

int	close_win_button(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
	exit(0);
	return (0);
}
