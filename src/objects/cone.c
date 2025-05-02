/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:17:15 by tleister          #+#    #+#             */
/*   Updated: 2025/05/02 13:52:58 by tleister         ###   ########.fr       */
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
	if (ft_vectdot(p->normal, dir) < 0)
		p->normal = ft_vectmult(p->normal, -1);
}

bool	ft_cone(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
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
