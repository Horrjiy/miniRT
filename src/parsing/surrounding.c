/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surrounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:37:40 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/27 15:25:05 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_ambient(t_data *data, char *line)
{
	if (data->all_surrnd[0])
		return (ft_parserr(data, 203));
	data->all_surrnd[0] = 1;
	split_line(data, &line);
	data->amb.amb_light = ft_convert_double(data);
	if (data->amb.amb_light > 1.0 || data->amb.amb_light < 0)
		ft_parserr(data, 205);
	free(data->str);
	split_line(data, &line);
	data->amb.rgb = ft_convert_rgb(data);
	free(data->str);
}

void	init_camera(t_data *data, char *line)
{
	if (data->all_surrnd[1])
		return (ft_parserr(data, 203));
	data->all_surrnd[1] = 1;
	split_line(data, &line);
	data->cam.pos = ft_convert_coords(data);
	free(data->str);
	split_line(data, &line);
	data->cam.vec = ft_convert_coords(data);
	ft_vectnorm2(&(data->cam.vec));
	if (isnan(data->cam.vec.x) || isnan(data->cam.vec.y)
		|| isnan(data->cam.vec.z))
		ft_parserr(data, 206);
	free(data->str);
	split_line(data, &line);
	data->cam.fov = ft_convert_double(data);
	if (data->cam.fov > 180.0 || data->cam.fov < 0.0)
		ft_parserr(data, 205);
	free(data->str);
}

void	init_light(t_data *data, char *line)
{
	if (data->all_surrnd[2])
		return (ft_parserr(data, 203));
	data->all_surrnd[2] = 1;
	split_line(data, &line);
	data->light.pos = ft_convert_coords(data);
	free(data->str);
	split_line(data, &line);
	data->light.bright = ft_convert_double(data);
	if (data->light.bright > 1.0 || data->light.bright < 0.0)
		free(data->str);
	split_line(data, &line);
	data->light.rgb = ft_convert_rgb(data);
	free(data->str);
}
