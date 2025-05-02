/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:12:07 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/02 13:51:58 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ft_plane(t_obj *obj, t_vect supv, t_vect dirv, t_hit *htp)
{
	t_pl	plane;
	double	t;
	double	temp;

	plane = obj->plane;
	temp = ft_vectdot(dirv, plane.nvec);
	if (temp == 0)
		return (false);
	t = -(ft_vectdot(ft_vectsub(supv, plane.pos), plane.nvec) / temp);
	if (t < 0)
		return (false);
	htp->dist = t;
	htp->obj = obj;
	htp->normal = plane.nvec;
	if (ft_vectdot(plane.nvec, dirv) < 0)
		htp->normal = ft_vectmult(plane.nvec, -1);
	htp->col = ft_rgbtod(plane.rgb);
	htp->point = ft_vectadd(supv, ft_vectmult(dirv, t));
	return (true);
}
