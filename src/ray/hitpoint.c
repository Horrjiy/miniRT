/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:26:07 by tleister          #+#    #+#             */
/*   Updated: 2025/04/29 15:27:29 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_hit	*ft_get_closest_hitpoint(t_coords or, t_vect dir, t_data *d)
{
	t_obj	*obj;
	t_hit	*point;
	double	min_dist;
	t_hit	*closest;

	t_hit *(*g_intersects[shape_amount])(t_obj *, t_coords, t_vect) = {&ft_sphere, &ft_plane, &ft_cylinder};
	closest = NULL;
	min_dist = INFINITY;
	obj = d->objects;
	while (obj)
	{
		point = g_intersects[(int)obj->type](obj, or, dir);
		if (point)
		{
			if (min_dist > point->dist)
			{
				free(closest);
				closest = point;
				min_dist = point->dist;
			}
		}
		obj = obj->next;
	}
	return (closest);
}
