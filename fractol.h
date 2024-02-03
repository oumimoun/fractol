/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 05:28:28 by oumimoun          #+#    #+#             */
/*   Updated: 2024/02/03 13:17:20 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>

# define WIDTH 800
# define HEIGHT 800

# define MAX_ITER 70

typedef struct s_fractal
{
	int		bpp;
	int		line_length;
	int		endian;
	int		color;
	int		pixel_index;
	int		iterator;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*set;
	void	*img;
	char	*addr;
	double	x;
	double	y;
	double	x_mlx;
	double	y_mlx;
	double	start_x;
	double	start_y;
	double	end_x;
	double	end_y;
	double	c_real;
	double	c_imag;
	double	x_temp;
	double	y_temp;
	double	zoom;

}	t_fractal;

int		ft_arg_is_valid(char *str);
int		ft_is_numerique(char c);
int		ft_strcmp(char *s1, char *s2);
int		close_win_button(t_fractal *fractal);
int		mouse_hook(int mousecode, int x, int y, t_fractal *fractal);
int		ft_apply_the_set_mandelbrot(t_fractal *fractal);
int		ft_apply_the_set_julia(t_fractal *fractal);
int		close_win(int keycode, t_fractal *fractal);

void	ft_print_error(char *str);
void	ft_setup_the_env(t_fractal *fractal, char *set);
void	ft_mapping_mandelbrot(t_fractal *fractal);
void	ft_mapping_julia(t_fractal *fractal);
void	ft_mandelbrot(t_fractal *fractal);
void	ft_julia(t_fractal *fractal);
void	ft_parce_args(t_fractal *fracal, char *name, char *s1, char *s2);
void	ft_check_double_point(char *str);

#endif