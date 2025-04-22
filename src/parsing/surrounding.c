/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surrounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:37:40 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/22 17:41:56 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// static void split_line(t_data *data, char *line)
// {
// 	(void)data;
// 	(void)line;
// }

void init_ambient(t_data *data, char *line)
{
	if(data->all_surroundings[0])
		return(ft_parserr(data, 203));
	data->all_surroundings[0] = 1;

	(void)data;
	(void)line;
}

void init_camera(t_data *data, char *line)
{
	if(data->all_surroundings[1])
		return(ft_parserr(data, 203));
	data->all_surroundings[1] = 1;
	
	(void)data;
	(void)line;
}

void init_light(t_data *data, char *line)
{
	if(data->all_surroundings[2])
		return(ft_parserr(data, 203));
	data->all_surroundings[2] = 1;

	(void)data;
	(void)line;
}
