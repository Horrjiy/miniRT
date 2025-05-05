/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:17:15 by tleister          #+#    #+#             */
/*   Updated: 2025/05/05 16:34:36 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// n=v − (r−r0) tan(θ)
// ∣r−r0∣

static void	set_hit(t_hit *p, t_coords or, t_vect dir, t_obj *obj)
{
	t_vect	tangential;

	p->col = ft_rgbtod(obj->cone.rgb);
	p->obj = obj;
	p->point = ft_vectadd(or, ft_vectmult(dir, p->dist));
	tangential = ft_vectcross(obj->cone.vec, ft_vectsub(obj->cone.pos,
				p->point));
	tangential = ft_vectcross(obj->cone.vec, ft_vectsub(p->point,
				obj->cone.pos));
	p->normal = ft_vectcross(tangential, ft_vectsub(p->point, obj->cone.pos));
	if (ft_vectdot(p->normal, dir) < 0)
		p->normal = ft_vectmult(p->normal, -1);
}

bool	ft_inf_cone(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	double	abc[3];
	t_vect	delta_p;
	double	temp_v[3];

	delta_p = ft_vectsub(or, obj->cone.pos);
	temp_v[0] = 1 + pow(obj->cone.dia / 2 / obj->cone.h, 2);
	temp_v[1] = ft_vectdot(dir, obj->cone.vec);
	temp_v[2] = ft_vectdot(delta_p, obj->cone.vec);
	abc[0] = 1 - temp_v[0] * pow(temp_v[1], 2);
	abc[1] = 2 * (ft_vectdot(dir, delta_p) - temp_v[0] * temp_v[1] * temp_v[2]);
	abc[2] = ft_vectdot(delta_p, delta_p) - temp_v[0] * pow(temp_v[2], 2);
	point->dist = ft_solve_quad_eq(abc);
	if (point->dist < 0)
		return (false);
	set_hit(point, or, dir, obj);
	return (true);
}

bool	ft_cone(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	t_hit	temp;
	double	dot;
	t_obj	pl;

	point->dist = INFINITY;
	if (ft_inf_cone(obj, or, dir, &temp))
	{
		dot = ft_vectdot(ft_vectsub(temp.point, obj->cone.pos), obj->cone.vec);
		if (dot > 0.0 && dot < obj->cone.h)
			*point = temp;
	}
	pl.plane.pos = ft_vectadd(obj->cone.pos, ft_vectmult(obj->cone.vec,
				obj->cone.h));
	pl.plane.nvec = obj->cone.vec;
	pl.plane.rgb = obj->cone.rgb;
	if (ft_plane(&pl, or, dir, &temp))
	{
		if (ft_vectdist(pl.plane.pos, temp.point) < obj->cone.dia / 2
			&& temp.dist < point->dist)
			*point = temp;
	}
	return (point->dist < INFINITY);
}
