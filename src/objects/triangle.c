/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:27:00 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/30 18:44:39 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	ft_isontriangle(t_hit *htp, t_tr trian)
{
	double	denom;
	double	barycent[3];
	t_vect	tvec[3];

	tvec[0] = ft_vectsub(trian.pt_c, trian.pt_a);
	tvec[1] = ft_vectsub(trian.pt_b, trian.pt_a);
	tvec[2] = ft_vectsub(htp->point, trian.pt_a);
	denom = ((ft_vectdot(tvec[0], tvec[0]) * ft_vectdot(tvec[1], tvec[1]))
			- (ft_vectdot(tvec[1], tvec[0]) * ft_vectdot(tvec[1], tvec[0])));
	barycent[COORD_V] = ((ft_vectdot(tvec[1], tvec[1]) * ft_vectdot(tvec[2],
					tvec[0])) - (ft_vectdot(tvec[1], tvec[0])
				* ft_vectdot(tvec[2], tvec[1]))) / denom;
	barycent[COORD_W] = ((ft_vectdot(tvec[0], tvec[0]) * ft_vectdot(tvec[2],
					tvec[1])) - (ft_vectdot(tvec[1], tvec[0])
				* ft_vectdot(tvec[2], tvec[0]))) / denom;
	barycent[COORD_U] = 1 - barycent[COORD_V] - barycent[COORD_W];
	if (barycent[COORD_U] + barycent[COORD_V] + barycent[COORD_W] == 1)
		if (barycent[COORD_U] >= 0 && barycent[COORD_V] >= 0
			&& barycent[COORD_W] >= 0)
			return (true);
	return (false);
}

bool	*ft_triangle(t_obj *obj, t_vect supv, t_vect dirv, t_hit *htp)
{
	t_tr	trian;
	double	t;
	double	temp;

	trian = obj->triang;
	htp->obj = obj;
	htp->normal = ft_vectcross(ft_vectsub(trian.pt_b, trian.pt_a),
		ft_vectsub(trian.pt_c, trian.pt_a));
	htp->col = ft_rgbtod(trian.rgb);
	temp = ft_vectdot(dirv, htp->normal);
	if (temp == 0)
		return (false);
	t = -((ft_vectdot(ft_vectsub(supv, trian.pt_a), htp->normal)) / temp);
	htp->dist = t;
	if (t < 0)
		return (false);
	htp->point = ft_vectadd(supv, ft_vectmult(dirv, t));
	if (ft_isontriangle(htp, trian) == false)
		return (false);
	return (true);
}
