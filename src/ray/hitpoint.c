/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:26:07 by tleister          #+#    #+#             */
/*   Updated: 2025/05/05 19:32:19 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// void	set_hit_cone(t_hit *p, t_coords or, t_vect dir, t_obj *obj)
bool	ft_get_closest_hitpoint(t_coords or, t_vect dir, t_data *d,
		t_hit *closest)
{
	t_obj	*obj;
	t_hit	point;
	double	min_dist;

	bool (*intersects[shape_amount])(t_obj *, t_coords, t_vect,
			t_hit *) = {&ft_sphere, &ft_plane, &ft_cylinder, &ft_cone,
		&ft_triangle};
	min_dist = INFINITY;
	obj = d->objects;
	while (obj)
	{
		if (intersects[(int)obj->type](obj, or, dir, &point))
		{
			if (min_dist > point.dist)
			{
				*closest = point;
				min_dist = point.dist;
			}
		}
		obj = obj->next;
	}
	return (min_dist < INFINITY);
}
