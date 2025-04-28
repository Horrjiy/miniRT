/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:36:31 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/28 10:21:00 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//Checks if the identifier is valid.
//If valid, redirects to the identifier's function.
static void	init_identifier(t_data *data, char **scene)
{
	int	i;

	i = 0;
	while (scene[i])
	{
		if (scene[i][0] == 'A' && !ft_iswhtspc(scene[i][1]))
			init_ambient(data, scene[i]);
		else if (scene[i][0] == 'C' && ft_iswhtspc(scene[i][1]))
			init_camera(data, scene[i]);
		else if (scene[i][0] == 'L' && ft_iswhtspc(scene[i][1]))
			init_light(data, scene[i]);
		else if (scene[i][0] == 's' && scene[i][1] == 'p'
				&& ft_iswhtspc(scene[i][2]))
			init_sphere(data, scene[i]);
		else if (scene[i][0] == 'p' && scene[i][1] == 'l'
				&& ft_iswhtspc(scene[i][2]))
			init_plane(data, scene[i]);
		else if (scene[i][0] == 'c' && scene[i][1] == 'y'
				&& ft_iswhtspc(scene[i][2]))
			init_cylinder(data, scene[i]);
		else
			ft_parserr(data, 202);
		i++;
	}
}

void	ft_analyze(t_data *data, int fd)
{
	data->objects = NULL;
	data->all_surroundings[0] = 0;
	data->all_surroundings[1] = 0;
	data->all_surroundings[2] = 0;
	data->temp = get_next_text(fd);
	if (!data->temp)
		return (ft_parserr(data, 201));
	data->scene = ft_split(data->temp, '\n');
	free(data->temp);
	if (!data->scene)
		return (ft_parserr(data, ENOMEM));
	init_identifier(data, data->scene);
}
