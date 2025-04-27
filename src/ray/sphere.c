/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:58:45 by tleister          #+#    #+#             */
/*   Updated: 2025/04/27 12:36:09 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_b_rgb	ft_convertrgb(t_rgbcolor col);

t_hit	*ft_sphere(t_obj *obj, t_coords or, t_vect dir, t_data *d)
{
	t_sp	sp;
	double	b;
	double	c;
	t_hit	*p;
	double	in_sqrt;
	double	a;

	sp = obj->sphere;
	a = ft_vectdot(dir, dir);
	b = 2 * ft_vectdot(dir, or) - 2 * ft_vectdot(dir, sp.pos);
	c = ft_vectdot(or, or) + ft_vectdot(sp.pos, sp.pos) - 2 * ft_vectdot(or,
			sp.pos) - (sp.dia / 2) * (sp.dia / 2);
	in_sqrt = b * b - 4 * a * c;
	p = malloc(sizeof(t_hit));
	if (in_sqrt <= 0 || p == NULL)
		return (free(p), NULL);
	in_sqrt = sqrt(in_sqrt);
	p->dist = (-b + in_sqrt) / (2 * a);
	if (p->dist <= 0 || (p->dist > (-b - in_sqrt) / (2 * a) && (-b - in_sqrt)
			/ (2 * a) > 0))
		p->dist = (-b - in_sqrt) / (2 * a);
	if (p->dist <= 0)
		return (free(p), NULL);
	p->col = ft_get_ligthcolor(ft_convertrgb(sp.rgb), d->amb.amb_light);
	p->obj = obj;
	p->point = ft_vectadd(or, ft_vectmult(dir, p->dist));
	p->normal = ft_vectnorm(ft_vectsub(p->point, sp.pos));
	return (p);
}
