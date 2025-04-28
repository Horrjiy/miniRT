/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:43:03 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/28 10:20:41 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	freearr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
}

void	free_data(t_data *data)
{
	void	*next;

	// if (data->temp)
	// 	free(data->temp);
	// if (data->scene)
	// 	freearr(data->scene);
	while (data->objects)
	{
		next = data->objects->next;
		free(data->objects);
		data->objects = next;
	}
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
}
