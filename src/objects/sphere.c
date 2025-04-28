/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:58:45 by tleister          #+#    #+#             */
/*   Updated: 2025/04/28 10:20:22 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void set_hit(t_hit *p, t_coords or, t_vect dir, t_obj *obj)
{
	p->col = ft_convertrgb(obj->sphere.rgb);
	p->obj = obj;
	p->point = ft_vectadd(or, ft_vectmult(dir, p->dist));
	p->normal = ft_vectnorm(ft_vectsub(p->point, obj->sphere.pos));
}

t_hit	*ft_sphere(t_obj *obj, t_coords or, t_vect dir)
{
	t_sp	sp;
	double	b;
	double	c;
	t_hit	*point;
	double	in_sqrt;
	double	a;

	sp = obj->sphere;
	a = ft_vectdot(dir, dir);
	b = 2 * ft_vectdot(dir, or) - 2 * ft_vectdot(dir, sp.pos);
	c = ft_vectdot(or, or) + ft_vectdot(sp.pos, sp.pos) - 2 * ft_vectdot(or,
			sp.pos) - (sp.dia / 2) * (sp.dia / 2);
	in_sqrt = b * b - 4 * a * c;
	point = malloc(sizeof(t_hit));
	if (in_sqrt <= 0 || point == NULL)
		return (free(point), NULL);
	in_sqrt = sqrt(in_sqrt);
	point->dist = (-b + in_sqrt) / (2 * a);
	if (point->dist <= 0 || (point->dist > (-b - in_sqrt) / (2 * a) && (-b - in_sqrt)
			/ (2 * a) > 0))
		point->dist = (-b - in_sqrt) / (2 * a);
	if (point->dist <= 0)
		return (free(point), NULL);
	set_hit(point, or, dir, obj);
	return (point);
}
