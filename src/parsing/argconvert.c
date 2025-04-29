/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:36:31 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/28 10:52:38 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// static void	printpars(t_data *data)
// {
// 	t_obj	*temp;

// 	temp = data->objects;
// 	printf("\n");
// 	printf("A: %g - rgb: %u %u %u\n", data->amb.amb_light, data->amb.rgb.r,
// 			data->amb.rgb.g, data->amb.rgb.b);
// 	printf("C: pos: %g %g %g - vec: %g %g %g - fov: %g\n", data->cam.pos.x,
// 			data->cam.pos.y, data->cam.pos.z, data->cam.vec.x, data->cam.vec.y,
// 			data->cam.vec.z, data->cam.fov);
// 	printf("L: pos: %g %g %g - br: %g - rgb: %u %u %u\n", data->light.pos.x,
// 			data->light.pos.y, data->light.pos.z, data->light.bright,
// 			data->light.rgb.r, data->light.rgb.g, data->light.rgb.b);
// 	printf("\n");
// 	while (temp)
// 	{
// 		if (temp->type == sphere)
// 			printf("sp: %g %g %g - dia: %g - rgb: %u %u %u\n",
// 					temp->sphere.pos.x,
// 					temp->sphere.pos.y,
// 					temp->sphere.pos.z,
// 					temp->sphere.dia,
// 					temp->sphere.rgb.r,
// 					temp->sphere.rgb.g,
// 					temp->sphere.rgb.b);
// 		else if (temp->type == plane)
// 			printf("pl: %g %g %g - vec: %g %g %g - rgb: %u %u %u\n",
// 					temp->plane.pos.x,
// 					temp->plane.pos.y,
// 					temp->plane.pos.z,
// 					temp->plane.nvec.x,
// 					temp->plane.nvec.y,
// 					temp->plane.nvec.z,
// 					temp->plane.rgb.r,
// 					temp->plane.rgb.g,
// 					temp->plane.rgb.b);
// 		else if (temp->type == cylinder)
// 			printf("cy: %g %g %g - vec: %g %g %g - dia: %g - h: %g - rgb: %u %u %u\n",\
// 					temp->cylinder.pos.x,\
// 					temp->cylinder.pos.y,\
// 					temp->cylinder.pos.z,\
// 					temp->cylinder.vec.x,\
// 					temp->cylinder.vec.y,\
// 					temp->cylinder.vec.z,\
// 					temp->cylinder.dia,\
// 					temp->cylinder.h,\
// 					temp->cylinder.rgb.r,\
// 					temp->cylinder.rgb.g,\
// 					temp->cylinder.rgb.b);
// 		temp = temp->next;
// 	}
// }

//Checks if the identifier is valid.
//If valid, redirects to the identifier's function.
static void	init_identifier(t_data *data, char **scene, char *line)
{
	int	i;

	i = 0;
	while (scene[i])
	{
		line = scene[i];
		if (scene[i][0] == 'A' && ft_iswhtspc(scene[i][1]))
			init_ambient(data, line);
		else if (scene[i][0] == 'C' && ft_iswhtspc(scene[i][1]))
			init_camera(data, line);
		else if (scene[i][0] == 'L' && ft_iswhtspc(scene[i][1]))
			init_light(data, line);
		else if (scene[i][0] == 's' && scene[i][1] == 'p'
				&& ft_iswhtspc(scene[i][2]))
			init_sphere(data, line);
		else if (scene[i][0] == 'p' && scene[i][1] == 'l'
				&& ft_iswhtspc(scene[i][2]))
			init_plane(data, line);
		else if (scene[i][0] == 'c' && scene[i][1] == 'y'
				&& ft_iswhtspc(scene[i][2]))
			init_cylinder(data, line);
		else
			ft_parserr(data, 202);
		i++;
	}
}

void	ft_analyze(t_data *data, int fd)
{
	data->objects = NULL;
	data->mlx = NULL;
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
	init_identifier(data, data->scene, NULL);
	if (!data->all_surrnd[0] || !data->all_surrnd[1] || !data->all_surrnd[2])
		return (ft_parserr(data, 203));
	// printpars(data);
}
