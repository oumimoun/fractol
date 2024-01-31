/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumimoun <oumimoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:12:54 by oumimoun          #+#    #+#             */
/*   Updated: 2024/01/26 14:43:22 by oumimoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>
#include <stdlib.h>
# include <limits.h>
# include <math.h>

int	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long	total;

	signe = 1;
	total = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= (-1);
		if (str[++i] == '+' || str[i] == '-' || str[i] == '\0')
			ft_print_error("Error");
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + str[i] - '0';
		if (str[++i] == '+' || str[i] == '-')
			ft_print_error("Error");
	}
	if ((total * signe) < INT_MIN || (total * signe) > INT_MAX)
		ft_print_error("Error");
	return ((int)(signe * total));
}

double ft_atof(char *str)
{
    int i;
    int signe;
    double total;
    double decimal;

    i = 0;
    signe = 1;
    total = 0.0;
    decimal = 0.1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            signe *= (-1);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        total = total * 10 + str[i] - '0';
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            total = total + (str[i] - '0') * decimal;
            decimal *= 0.1;
            i++;
        }
    }
    return (signe * total);
}

// int main()
// {
//     char str[] = "       268       6+-";
//     float result = ft_atof(str);
//     printf("Result: %f\n", result);

//     return 0;
// }

