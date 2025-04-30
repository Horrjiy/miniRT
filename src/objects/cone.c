/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:17:15 by tleister          #+#    #+#             */
/*   Updated: 2025/04/30 19:01:19 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// B=2⋅((o−C−(v⋅(o−C))⋅v)⋅(d−(v⋅d)⋅v))
// C=|o−C−(v⋅(o−C))⋅v|^2−													((v⋅(o−C))⋅tan(θ))^2

// A1 = v⋅(o−C)
// A2 = v⋅d

static void	set_hit(t_hit *p, t_coords or, t_vect dir, t_obj *obj)
{
	t_vect	tangential;

	p->col = ft_rgbtod(obj->cone.rgb);
	p->obj = obj;
	p->point = ft_vectadd(or, ft_vectmult(dir, p->dist));
	tangential = ft_vectcross(obj->cone.vec, ft_vectsub(obj->cone.pos,
				p->point));
	p->normal = ft_vectcross(tangential, ft_vectsub(obj->cone.pos, p->point));
}

bool ft_cone(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	t_co	co;
	t_vect	c;
	double	abc[3];
	double	cos_th2;
	double	dv;
	double	co_v;

	co = obj->cone;
	c = ft_vectsub(or, co.pos);
	cos_th2 = pow(cos(atan(co.dia / co.h / 2)), 2);
	dv = ft_vectdot(dir, co.vec);
	co_v = ft_vectdot(c, co.vec);
	abc[0] = dv * dv - cos_th2;
	abc[1] = 2 * (dv * co_v - ft_vectdot(dir, c) * cos_th2);
	abc[2] = co_v * co_v - ft_vectdot(c, c) * cos_th2;
	point->dist = ft_solve_quad_eq(abc);
	if (point->dist < 0)
		return (false);
	set_hit(point, or, dir, obj);
	return (true);
}

// bool ft_cone(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
// {
// 	t_hit	*temp;
// 	t_obj	pl;

// 	point = NULL;
// 	pl.plane.nvec = obj->cone.vec;
// 	pl.plane.pos = ft_vectadd(obj->cone.pos, ft_vectmult(obj->cone.vec,
// 				obj->cone.h));
// 	pl.plane.rgb = obj->cone.rgb;
// 	if(ft_plane(&pl, or, dir, temp));
// 		if (pow(ft_vectdist(temp->point, pl.plane.pos), 2) <= pow(obj->cone.h, 2) + pow(obj->cone.dia / 2, 2))
// 			point = temp;
	
// }
