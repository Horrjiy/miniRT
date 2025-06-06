/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:36:26 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/05 16:44:34 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	ft_fraction(int i, char *str)
{
	double	divisor;
	double	frac;

	divisor = 10.0;
	frac = 0.0;
	i++;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		frac += ((str[i] - '0') / divisor);
		divisor *= 10;
		i++;
	}
	return (frac);
}

double	ft_atodb(char *str)
{
	int			i;
	long double	number;
	int			sign;

	number = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
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
		return ((number + ft_fraction(i, str)) * sign);
	return (number * sign);
}

int	ft_safe_atoi(char *str, t_data *data)
{
	int			i;
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	i = 0;
	if (!(ft_isdigit(str[0]) || str[0] == '-'))
		ft_parserr(data, 204);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		number = number * 10;
		number += str[i] - '0';
		i++;
	}
	if (number > 2147483647 || number < -2147483648 || ft_comlen(str) > 11)
		ft_parserr(data, 204);
	return ((int)(number * sign));
}

unsigned char	ft_safe_atouc(char *str, t_data *data)
{
	int	i;

	i = ft_safe_atoi(str, data);
	if (i < 0 || i > 255)
		ft_parserr(data, 205);
	return ((unsigned char)i);
}
