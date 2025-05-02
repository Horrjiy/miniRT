/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:43:03 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/02 11:14:46 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	freearr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		freen(&strarr[i]);
		i++;
	}
	free(strarr);
}

void freen(char **str)
{
	free(*str);
	*str = NULL;
}

void	free_data(t_data *data)
{
	void *next = NULL;

	if (data->str)
		freen(&(data->str));
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
