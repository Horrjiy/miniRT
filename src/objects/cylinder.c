/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:06:02 by tleister          #+#    #+#             */
/*   Updated: 2025/05/06 10:41:07 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_hit(t_hit *p, t_coords or, t_vect dir, t_obj *obj)
{
	p->col = ft_rgbtod(obj->cylinder.rgb);
	p->obj = obj;
	p->point = ft_vectadd(or, ft_vectmult(dir, p->dist));
	p->normal = ft_vectnorm(ft_vectsub(p->point, ft_vectadd(obj->cylinder.pos,
					ft_vectmult(obj->cylinder.vec, ft_vectdot(obj->cylinder.vec,
							ft_vectsub(p->point, obj->cylinder.pos))))));
}

static bool	check_hit(t_hit *point, t_hit temp, t_cy cy)
{
	if (pow(ft_vectdist(temp.point, cy.pos), 2) <= pow(cy.h / 2, 2) + pow(cy.dia
			/ 2, 2) && temp.dist < point->dist)
	{
		*point = temp;
		return (true);
	}
	return (false);
}

// try infinite cylinder for now
bool	ft_inf_cylinder(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	t_vect	oc;
	double	abc[3];

	oc = ft_vectsub(or, obj->cylinder.pos);
	abc[0] = pow(ft_vectdot(obj->cylinder.vec, dir), 2) - 1;
	abc[1] = 2 * ft_vectdot(oc, obj->cylinder.vec)
		* ft_vectdot(obj->cylinder.vec, dir) - 2 * (ft_vectdot(oc, dir));
	abc[2] = pow(obj->cylinder.dia / 2, 2) + pow(ft_vectdot(oc,
				obj->cylinder.vec), 2) - ft_vectdot(oc, oc);
	point->dist = ft_solve_quad_eq(abc);
	if (point->dist < 0)
		return (false);
	set_hit(point, or, dir, obj);
	return (true);
}

bool	ft_cylinder(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	t_obj	pl;
	t_hit	temp;
	bool	hit;

	point->dist = INFINITY;
	hit = false;
	pl.plane.nvec = obj->cylinder.vec;
	pl.plane.pos = ft_vectadd(obj->cylinder.pos, ft_vectmult(obj->cylinder.vec,
				obj->cylinder.h / 2));
	pl.plane.rgb = obj->cylinder.rgb;
	if (ft_plane(&pl, or, dir, &temp))
		hit = check_hit(point, temp, obj->cylinder) || hit;
	pl.plane.pos = ft_vectadd(obj->cylinder.pos, ft_vectmult(obj->cylinder.vec,
				-obj->cylinder.h / 2));
	if (ft_plane(&pl, or, dir, &temp))
		hit = check_hit(point, temp, obj->cylinder) || hit;
	if (ft_inf_cylinder(obj, or, dir, &temp))
		hit = check_hit(point, temp, obj->cylinder) || hit;
	return (hit);
}
