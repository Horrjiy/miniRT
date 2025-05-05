/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:58:45 by tleister          #+#    #+#             */
/*   Updated: 2025/05/05 16:44:12 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_hit(t_hit *p, t_coords or, t_vect dir, t_obj *obj)
{
	p->col = ft_rgbtod(obj->sphere.rgb);
	p->obj = obj;
	p->point = ft_vectadd(or, ft_vectmult(dir, p->dist));
	p->normal = ft_vectnorm(ft_vectsub(p->point, obj->sphere.pos));
}

bool	ft_sphere(t_obj *obj, t_coords or, t_vect dir, t_hit *point)
{
	t_sp	sp;
	double	abc[3];

	sp = obj->sphere;
	abc[0] = 1;
	abc[1] = 2 * ft_vectdot(dir, or) - 2 * ft_vectdot(dir, sp.pos);
	abc[2] = ft_vectdot(or, or) + ft_vectdot(sp.pos, sp.pos) - 2
		* ft_vectdot(or, sp.pos) - (sp.dia / 2) * (sp.dia / 2);
	point->dist = ft_solve_quad_eq(abc);
	if (point->dist < 0)
		return (false);
	set_hit(point, or, dir, obj);
	return (true);
}
