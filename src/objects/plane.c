/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:12:07 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/28 16:07:43 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_hit	*ft_plane(t_obj *obj, t_vect supv, t_vect dirv)
{
	t_hit	*htp;
	t_pl	plane;
	double	t;
	double	temp;
	
	htp = malloc(sizeof(t_hit));
	if (!htp)
		return (NULL);
	plane = obj->plane;
	htp->obj = obj;
	htp->normal = plane.nvec;
	htp->col = ft_convertrgb(plane.rgb);
	temp = ft_vectdot(dirv, plane.nvec);
	if(temp == 0)
		return(free(htp), NULL);
	t = -((ft_vectdot(ft_vectsub(supv, plane.pos), plane.nvec)) / temp);
	htp->dist = t;
	htp->point = ft_vectadd(supv, ft_vectmult(dirv, t));
	if(t < 0)
		return(NULL);
	return (htp);
}
