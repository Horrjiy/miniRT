/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:06:02 by tleister          #+#    #+#             */
/*   Updated: 2025/05/02 11:29:23 by tleister         ###   ########.fr       */
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

// try infinite cylinder for now
bool	ft_inf_cylinder(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	t_cy	cy;
	double	abc[3];

	cy = obj->cylinder;
	abc[0] = pow(ft_vectdot(cy.vec, dir), 2) - ft_vectdot(dir, dir);
	abc[1] = 2 * ft_vectdot(ft_vectsub(or, cy.pos), cy.vec) * ft_vectdot(cy.vec,
			dir) - 2 * (ft_vectdot(ft_vectsub(or, cy.pos), dir));
	abc[2] = pow(cy.dia / 2, 2) + pow(ft_vectdot(ft_vectsub(or, cy.pos),
				cy.vec), 2) - ft_vectdot(ft_vectsub(or, cy.pos), ft_vectsub(or,
				cy.pos));
	point->dist = ft_solve_quad_eq(abc);
	if (point->dist < 0)
		return (false);
	set_hit(point, or, dir, obj);
	return (true);
}

bool	ft_cylinder(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	t_cy	cy;
	t_obj	pl;
	t_hit	temp;
	bool	hit;

	hit = false;
	cy = obj->cylinder;
	pl.plane.nvec = cy.vec;
	pl.plane.pos = ft_vectadd(cy.pos, ft_vectmult(cy.vec, cy.h / 2));
	pl.plane.rgb = cy.rgb;
	if (ft_plane(&pl, or, dir, &temp))
	{
		if (pow(ft_vectdist(temp.point, cy.pos), 2) <= pow(cy.h / 2, 2)
			+ pow(cy.dia / 2, 2) && (!hit || temp.dist < point->dist))
		{
			*point = temp;
			hit = true;
		}
	}
	pl.plane.pos = ft_vectadd(cy.pos, ft_vectmult(cy.vec, -cy.h / 2));
	if (ft_plane(&pl, or, dir, &temp))
	{
		if (pow(ft_vectdist(temp.point, cy.pos), 2) <= pow(cy.h / 2, 2)
			+ pow(cy.dia / 2, 2) && (!hit || temp.dist < point->dist))
		{
			*point = temp;
			hit = true;
		}
	}
	if (ft_inf_cylinder(obj, or, dir, &temp))
	{
		if (pow(ft_vectdist(temp.point, cy.pos), 2) <= pow(cy.h / 2, 2)
			+ pow(cy.dia / 2, 2) && (!hit || temp.dist < point->dist))
		{
			*point = temp;
			hit = true;
		}
	}
	return (hit);
}
