/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 05:28:28 by oumimoun          #+#    #+#             */
/*   Updated: 2024/01/31 15:56:03 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <mlx.h>
#include <limits.h>

#define WIDTH 800
#define HEIGHT 800

#define MAX_ITER 70


typedef struct s_fractal
{
	void *mlx_ptr;
	void *mlx_win;
	char *set;
	//
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
	//
	double x;
	double y;
	//
	double x_real;
	double y_real;
	//
	double start_x;
	double start_y;
	double end_x;
	double end_y;
	// 
	double c_real;
	double c_imag;
	//
	double xtemp;
	double ytemp;
	//
	int color;
	int pixel_index;
	int iterator;
	double zoom;

} t_fractal;

int ft_arg_is_valid(char *str);
int ft_is_numerique(char c);
int ft_strcmp(char *s1, char *s2);
int ft_atoi(char *str);
void ft_print_error(char *str);
void ft_setup_the_env(t_fractal *fractal, char *set);
void ft_mapping_mandelbrot(t_fractal *fractal);
void ft_mapping_julia(t_fractal *fractal);

void ft_mandelbrot(t_fractal *fractal);
void ft_julia(t_fractal *fractal);

int mouse_hook(int mousecode, int x, int y, t_fractal *fractal);
int ft_apply_the_set_mandelbrot(t_fractal *fractal);
int ft_apply_the_set_julia(t_fractal *fractal);

#endif