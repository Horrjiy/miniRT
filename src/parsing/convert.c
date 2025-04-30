/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:09:29 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/29 19:43:49 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

size_t	ft_comlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] && s[len] != ',')
		len++;
	return (len);
}

static bool	check_input(char *temp, int minus, int period, int comma)
{
	int	i;

	i = 0;
	if (!ft_isdigit(temp[i]) && temp[i++] != '-')
		return (false);
	if (!ft_isdigit(temp[ft_strlen(temp) - 1]))
		return (false);
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]) && temp[i] != ',' && temp[i] != '.'
			&& temp[i] != '-')
			return (false);
		if (temp[i] == '-' && !ft_iswhtspc(temp[i - 1]) && temp[i - 1] != ',')
			return (false);
		if (temp[i] == ',')
			comma--;
		if (temp[i] == '-')
			minus--;
		if (temp[i] == '.')
			period--;
		i++;
	}
	if (minus < 0 || comma != 0 || period < 0)
		return (false);
	return (true);
}

double	ft_convert_double(t_data *data)
{
	if (check_input(data->str, 1, 1, 0) == false)
		ft_parserr(data, 204);
	return (ft_atodb(data->str));
}

t_rgb	ft_convert_rgb(t_data *data)
{
	char	*temp;
	t_rgb	color;

	temp = data->str;
	if (check_input(temp, 0, 0, 2) == false)
		ft_parserr(data, 204);
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
	char		*temp;
	t_coords	coord;

	temp = data->str;
	if (check_input(temp, 3, 3, 2) == false)
		ft_parserr(data, 204);
	coord.x = ft_atodb(temp);
	while (*(temp) && *(temp) != ',')
		temp++;
	temp++;
	coord.y = ft_atodb(temp);
	while (*(temp) && *(temp) != ',')
		temp++;
	temp++;
	coord.z = ft_atodb(temp);
	return (coord);
}
