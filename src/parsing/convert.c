/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:09:29 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/25 17:14:09 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	ft_convert_double(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if (!ft_isdigit(data->str[i]) && data->str[i] != '.'
			&& data->str[i] != '-')
			ft_parserr(data, 204);
		i++;
	}
	return (ft_atodb(data->str));
}

t_rgb	ft_convert_rgb(t_data *data)
{
	int		i;
	char	*temp;
	t_rgb	color;

	i = 0;
	temp = data->str;
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]) && temp[i] != ',')
			ft_parserr(data, 204);
		i++;
	}
	color.r = ft_safe_atouc(temp, data);
	while (*(temp) && *(temp) != ',')
		temp++;
	temp++;
	color.g = ft_safe_atouc(temp, data);
	while (*(temp) && *(temp) != ',')
		temp++;
	temp++;
	color.b = ft_safe_atouc(temp, data);
	return (color);
}

t_coords	ft_convert_coords(t_data *data)
{
	int			i;
	char		*temp;
	t_coords	coord;

	i = 0;
	temp = data->str;
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]) && temp[i] != ',' && temp[i] != '-')
			ft_parserr(data, 204);
		i++;
	}
	coord.x = ft_safe_atoi(temp, data);
	while (*(temp) && *(temp) != ',')
		temp++;
	temp++;
	coord.y = ft_safe_atoi(temp, data);
	while (*(temp) && *(temp) != ',')
		temp++;
	temp++;
	coord.z = ft_safe_atoi(temp, data);
	return (coord);
}
