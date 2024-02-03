/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:11:30 by oumimoun          #+#    #+#             */
/*   Updated: 2024/02/03 13:08:12 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_error(char *str)
{
	int	i;

	i = 0;
	write(2, "\033[0;31m", 8);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\033[0m", 5);
	write(2, "\n", 1);
	exit(1);
}

int	ft_is_numerique(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_arg_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_numerique(str[i]))
			i++;
		else if (str[i] == '+')
			i++;
		else if (str[i] == '-')
			i++;
		else if (str[i] == '.')
			i++;
		else if (str[i] == ' ')
			i++;
		else
			ft_print_error("Try using ./fractol <M or J>");
	}
	return (1);
}

void	ft_check_double_point(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			flag++;
			if (flag > 1)
				ft_print_error("Try using ./fractol <M or J>");
		}
		i++;
	}
}
