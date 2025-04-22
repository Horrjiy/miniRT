/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:36:26 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/22 17:44:20 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	ft_atodb(char *str)
{
	int		i;
	double	number;
	double	frac;
	double	divisor;
	int		sign;

	number = 0.0;
	frac = 0.0;
	divisor = 10.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		number = number * 10;
		number += str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while ((str[i] >= '0' && str[i] <= '9'))
		{
			frac += ((str[i] - '0') / divisor);
			divisor *= 10;
			i++;
		}
	}
	return ((number + frac) * sign);
}
