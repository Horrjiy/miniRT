/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:06:02 by tleister          #+#    #+#             */
/*   Updated: 2025/04/29 17:21:15 by tleister         ###   ########.fr       */
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
t_hit	*ft_inf_cylinder(t_obj *obj, t_coords or, t_vect dir)
{
	t_cy	cy;
	double	a;
	double	b;
	double	c;
	double	in_sqrt;
	t_hit	*point;

	cy = obj->cylinder;
	a = pow(ft_vectdot(cy.vec, dir), 2) - ft_vectdot(dir, dir);
	b = 2 * ft_vectdot(ft_vectsub(or, cy.pos), cy.vec) * ft_vectdot(cy.vec, dir)
		- 2 * (ft_vectdot(ft_vectsub(or, cy.pos), dir));
	c = pow(cy.dia / 2, 2) + pow(ft_vectdot(ft_vectsub(or, cy.pos), cy.vec), 2)
		- ft_vectdot(ft_vectsub(or, cy.pos), ft_vectsub(or, cy.pos));
	in_sqrt = b * b - 4 * a * c;
	point = malloc(sizeof(t_hit));
	if (in_sqrt < 0 || point == NULL)
		return (free(point), NULL);
	in_sqrt = sqrt(in_sqrt);
	point->dist = (-b + in_sqrt) / (2 * a);
	if (point->dist < 0 || (point->dist > (-b - in_sqrt) / (2 * a) && (-b
				- in_sqrt) / (2 * a) > 0))
		point->dist = (-b - in_sqrt) / (2 * a);
	if (point->dist < 0)
		return (free(point), NULL);
	set_hit(point, or, dir, obj);
	return (point);
}

// static void	replace_point(t_hit **point, t_hit *temp, t_cy cy)
// {
// 	if (temp && pow(ft_vectdist(temp->point, cy.pos),2) <= pow(cy.h / 2, 2) + pow(cy.dia / 2, 2)
// 		&& (!(*point) || temp->dist < (*point)->dist))
// 	{
// 		free(*point);
// 		*point = temp;
// 	}
// 	else
// 		free(temp);
// }

t_hit	*ft_cylinder(t_obj *obj, t_coords or, t_vect dir)
{
	t_cy	cy;
	t_obj	pl;
	t_hit	*point;
	t_hit	*temp;

	point = NULL;
	cy = obj->cylinder;
	pl.plane.nvec = cy.vec;
	pl.plane.pos = ft_vectadd(cy.pos, ft_vectmult(cy.vec, cy.h / 2));
	pl.plane.rgb = cy.rgb;
	temp = ft_plane(&pl, or, dir);
	// replace_point(&point, temp, cy);
	if (temp && pow(ft_vectdist(temp->point, cy.pos),2) <= pow(cy.h / 2, 2) + pow(cy.dia / 2, 2) && (!point || temp->dist < point->dist))
		(free(point),point = temp);
	pl.plane.pos = ft_vectadd(cy.pos, ft_vectmult(cy.vec, -cy.h / 2));
	temp = ft_plane(&pl, or, dir);
	// replace_point(&point, temp, cy);
	if (temp && pow(ft_vectdist(temp->point, cy.pos),2) <= pow(cy.h / 2, 2) + pow(cy.dia / 2, 2) && (!point || temp->dist < point->dist))
		(free(point),point = temp);
	temp = ft_inf_cylinder(obj, or, dir);
	// replace_point(&point, temp, cy);
	if (temp && pow(ft_vectdist(temp->point, cy.pos),2) <= pow(cy.h / 2, 2) + pow(cy.dia / 2, 2) && (!point || temp->dist < point->dist))
		return (free(point),temp);
	return point;
}
