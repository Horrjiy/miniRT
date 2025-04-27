/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligths.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:59:10 by tleister          #+#    #+#             */
/*   Updated: 2025/04/27 14:19:36 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_b_rgb	ft_get_ligthcolor(t_b_rgb light, double p2)
{
	t_b_rgb	c;

	// printf("\tp2: %g", p2);
	if (p2 > 1)
		p2 = 1;
	else if (p2 < 0)
		p2 = 0;
	c.r = light.r * p2;
	c.g = light.g * p2;
	c.b = light.b * p2;
	return (c);
}

static t_b_rgb	ft_mix_color(t_hit *hit, t_vect ligth_dir, t_data *d)
{
	t_b_rgb	ligth_col;
	double	dot_p;

	// ft_vectprint("before: %l", hit->col);
	dot_p = ft_vectdot(ligth_dir, hit->normal);
	// printf("\tdot_p: %g\n", dot_p);
	ligth_col = ft_get_ligthcolor(ft_convertrgb(d->light.rgb), d->light.bright
			* dot_p);
	// ft_vectprint("\t%l", ligth_col);
	hit->col.r += ligth_col.r;
	hit->col.g += ligth_col.g;
	hit->col.b += ligth_col.b;
	if (hit->col.r > 1)
		hit->col.r = 1;
	if (hit->col.g > 1)
		hit->col.g = 1;
	if (hit->col.b > 1)
		hit->col.b = 1;
	return (hit->col);
}

t_b_rgb	ft_check_ligth(t_hit *hit, t_data *d)
{
	t_vect	dir;
	t_hit	*ligth_hit;
	dir = ft_vectnorm(ft_vectsub(d->light.pos, hit->point));
	ligth_hit = ft_get_closest_hitpoint(ft_vectadd(hit->point,ft_vectmult(dir, 0.001)), dir, d);
	if (ligth_hit)
	{
		// ft_vectprint("\nhit:\t%v\n", hit->point);
		// ft_vectprint("ligth:\t%v\n", ligth_hit->point);
		return (free(ligth_hit), hit->col);
	}
	// printf("change\n");
	return (ft_mix_color(hit, dir, d));
}
