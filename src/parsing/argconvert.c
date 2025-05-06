/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:36:31 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/06 10:05:15 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_identifier_helper(t_data *data, char *line)
{
	if (!ft_strncmp(line, "sp", 2) && ft_iswhtspc(line[2]))
		init_sphere(data, line);
	else if (!ft_strncmp(line, "pl", 2) && ft_iswhtspc(line[2]))
		init_plane(data, line);
	else if (!ft_strncmp(line, "cy", 2) && ft_iswhtspc(line[2]))
		init_cylinder(data, line);
	else if (!ft_strncmp(line, "tr", 2) && ft_iswhtspc(line[2]))
		init_triangle(data, line);
	else if (!ft_strncmp(line, "co", 2) && ft_iswhtspc(line[2]))
		init_cone(data, line);
	else
		ft_parserr(data, 202);
}

// Checks if the identifier is valid.
// If valid, redirects to the identifier's function.
static void	init_identifier(t_data *data, char **scene)
{
	char	*line;
	int		i;

	i = 0;
	while (scene[i])
	{
		line = scene[i];
		while (*line && ft_iswhtspc(*line))
			line++;
		if (ft_strlen(line) < 9)
			ft_parserr(data, 202);
		if (line[0] == 'A' && ft_iswhtspc(line[1]))
			init_ambient(data, line);
		else if (line[0] == 'C' && ft_iswhtspc(line[1]))
			init_camera(data, line);
		else if (line[0] == 'L' && ft_iswhtspc(line[1]))
			init_light(data, line);
		else
			ft_identifier_helper(data, line);
		i++;
	}
}

void	ft_analyze(t_data *data, int fd)
{
	data->objects = NULL;
	data->scene = NULL;
	data->mlx = NULL;
	data->all_surrnd[0] = 0;
	data->all_surrnd[1] = 0;
	data->all_surrnd[2] = 0;
	data->str = get_next_text(fd);
	close(fd);
	if (!data->str)
		return (ft_parserr(data, 201));
	data->scene = ft_split(data->str, '\n');
	if (!data->scene)
		return (ft_parserr(data, ENOMEM));
	freen(&data->str);
	init_identifier(data, data->scene);
	if (!data->all_surrnd[0] || !data->all_surrnd[1] || !data->all_surrnd[2])
		return (ft_parserr(data, 203));
}
