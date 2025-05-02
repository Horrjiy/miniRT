/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:12:07 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/02 11:26:11 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ft_plane(t_obj *obj, t_vect supv, t_vect dirv, t_hit *htp)
{
	t_pl	plane;
	double	t;
	double	temp;

	plane = obj->plane;
	htp->obj = obj;
	htp->normal = plane.nvec;
	htp->col = ft_rgbtod(plane.rgb);
	temp = ft_vectdot(dirv, plane.nvec);
	if (temp == 0)
		return (false);
	t = -((ft_vectdot(ft_vectsub(supv, plane.pos), plane.nvec)) / temp);
	htp->dist = t;
	if (t < 0)
		return (false);
	htp->point = ft_vectadd(supv, ft_vectmult(dirv, t));
	return (true);
}
