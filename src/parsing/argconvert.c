/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:36:31 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/25 18:10:50 by mpoplow          ###   ########.fr       */
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
		if (scene[i][0] == 'A' && ft_iswhtspc(scene[i][1]))
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
	data->all_surrnd[0] = 0;
	data->all_surrnd[1] = 0;
	data->all_surrnd[2] = 0;
	data->str = get_next_text(fd);
	if (!data->str)
		return (ft_parserr(data, 201));
	data->scene = ft_split(data->str, '\n');
	if (!data->scene)
	return (ft_parserr(data, ENOMEM));
	free(data->str);
	data->str = NULL;
	init_identifier(data, data->scene);
	if(!data->all_surrnd[0] || !data->all_surrnd[1] || !data->all_surrnd[2])
		return (ft_parserr(data, 203));
}

// printf("Regen: %s\n", scene[i]);
// printf("A: %g - rgb: %u %u %u\n", data->amb.amb_light, data->amb.rgb.r, data->amb.rgb.g, data->amb.rgb.b);
// printf("C: pos: %g %g %g - vec: %g %g %g - fov: %g\n", data->cam.pos.x, data->cam.pos.y, data->cam.pos.z, data->cam.vec.x, data->cam.vec.y, data->cam.vec.z, data->cam.fov);
// printf("L: pos: %g %g %g - br: %g - rgb: %u %u %u\n", data->light.pos.x, data->light.pos.y, data->light.pos.z, data->light.bright, data->light.rgb.r, data->light.rgb.g, data->light.rgb.b);
