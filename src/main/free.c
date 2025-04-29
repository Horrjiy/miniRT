/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:43:03 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/28 15:17:36 by tleister         ###   ########.fr       */
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
	void *next = NULL;

	// if (data->str)
	// 	free(data->str);
	if (data->scene)
		freearr(data->scene);
	while (data->objects)
	{
		next = data->objects->next;
		free(data->objects);
		data->objects = next;
	}
	if (data->mlx)
	{
		mlx_delete_image(data->mlx, data->img);
		mlx_terminate(data->mlx);
	}
}
