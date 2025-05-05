/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:37:42 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/05 16:33:53 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_sphere(t_data *data, char *line)
{
	t_obj	*temp;

	ft_node_addback(&(data->objects), init_object_node(sphere, data));
	temp = ft_lastnode(data->objects);
	split_line(data, &line);
	temp->sphere.pos = ft_convert_coords(data);
	freen(&data->str);
	split_line(data, &line);
	temp->sphere.dia = ft_convert_double(data);
	freen(&data->str);
	split_line(data, &line);
	temp->sphere.rgb = ft_convert_rgb(data);
	freen(&data->str);
}

void	init_plane(t_data *data, char *line)
{
	t_obj	*temp;

	ft_node_addback(&(data->objects), init_object_node(plane, data));
	temp = ft_lastnode(data->objects);
	split_line(data, &line);
	temp->plane.pos = ft_convert_coords(data);
	freen(&data->str);
	split_line(data, &line);
	temp->plane.nvec = ft_convert_coords(data);
	ft_vectnorm2(&(temp->plane.nvec));
	if (isnan(temp->plane.nvec.x) || isnan(temp->plane.nvec.y)
		|| isnan(temp->plane.nvec.z))
		ft_parserr(data, 206);
	freen(&data->str);
	split_line(data, &line);
	temp->plane.rgb = ft_convert_rgb(data);
	freen(&data->str);
}

void	init_cylinder(t_data *data, char *line)
{
	t_obj	*temp;

	ft_node_addback(&(data->objects), init_object_node(cylinder, data));
	temp = ft_lastnode(data->objects);
	split_line(data, &line);
	temp->cylinder.pos = ft_convert_coords(data);
	freen(&data->str);
	split_line(data, &line);
	temp->cylinder.vec = ft_convert_coords(data);
	ft_vectnorm2(&(temp->cylinder.vec));
	if (isnan(temp->cylinder.vec.x) || isnan(temp->cylinder.vec.y)
		|| isnan(temp->cylinder.vec.z))
		ft_parserr(data, 206);
	freen(&data->str);
	split_line(data, &line);
	temp->cylinder.dia = ft_convert_double(data);
	freen(&data->str);
	split_line(data, &line);
	temp->cylinder.h = ft_convert_double(data);
	freen(&data->str);
	split_line(data, &line);
	temp->cylinder.rgb = ft_convert_rgb(data);
	freen(&data->str);
}

void	init_cone(t_data *data, char *line)
{
	t_obj	*temp;

	ft_node_addback(&(data->objects), init_object_node(cone, data));
	temp = ft_lastnode(data->objects);
	split_line(data, &line);
	temp->cone.pos = ft_convert_coords(data);
	freen(&data->str);
	split_line(data, &line);
	temp->cone.vec = ft_convert_coords(data);
	ft_vectnorm2(&(temp->cone.vec));
	if (isnan(temp->cone.vec.x) || isnan(temp->cone.vec.y)
		|| isnan(temp->cone.vec.z))
		ft_parserr(data, 206);
	freen(&data->str);
	split_line(data, &line);
	temp->cone.dia = ft_convert_double(data);
	freen(&data->str);
	split_line(data, &line);
	temp->cone.h = ft_convert_double(data);
	freen(&data->str);
	split_line(data, &line);
	temp->cone.rgb = ft_convert_rgb(data);
	freen(&data->str);
}
