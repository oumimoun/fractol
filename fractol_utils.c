/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:11:30 by oumimoun          #+#    #+#             */
/*   Updated: 2024/01/25 19:27:53 by oumimoun         ###   ########.fr       */
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

void ft_print_error(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    write(2, "\n", 1);
    exit(1);
}

int ft_is_numerique(char c)
{
    if (c >= '1' && c <= '9')
        return (1);
    return (0);
}

int ft_arg_is_valid(char *str)
{
	int i;

	i = 0;
	while (str)
	{
    	if (ft_is_numerique(str[i]) || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}
