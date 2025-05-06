/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:23:01 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/06 12:17:03 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	clip_light(t_b_rgb *col)
{
	if (col->r > 1)
		col->r = 1;
	if (col->g > 1)
		col->g = 1;
	if (col->b > 1)
		col->b = 1;
	if (col->r < 0)
		col->r = 0;
	if (col->g < 0)
		col->g = 0;
	if (col->b < 0)
		col->b = 0;
}

static t_b_rgb	get_specular(t_hit *hit, t_vect light_dir, t_vect pixelv,
		t_l light)
{
	t_b_rgb	l;
	double	dot_p;
	t_vect	r1;

	dot_p = ft_vectdot(light_dir, hit->normal);
	r1 = ft_vectnorm(ft_vectsub(ft_vectmult(hit->normal, 2 * dot_p),
				light_dir));
	dot_p = ft_vectdot(r1, ft_vectmult(pixelv, -1));
	if (dot_p < 0)
		return (hit->col);
	l = ft_rgbtod(light.rgb);
	hit->col.r += l.r * light.bright * pow(dot_p, 32);
	hit->col.g += l.g * light.bright * pow(dot_p, 32);
	hit->col.b += l.b * light.bright * pow(dot_p, 32);
	clip_light(&hit->col);
	return (hit->col);
}

static t_b_rgb	get_diffuse(t_hit *hit, t_vect light_dir, t_l light)
{
	double	dot_p;
	t_b_rgb	l;

	dot_p = ft_vectdot(light_dir, hit->normal);
	if (dot_p < 0)
		dot_p = ft_vectdot(light_dir, ft_vectmult(hit->normal, -1));
	l = ft_rgbtod(light.rgb);
	hit->col.r += l.r * hit->col.r * light.bright * dot_p;
	hit->col.g += l.g * hit->col.g * light.bright * dot_p;
	hit->col.b += l.b * hit->col.b * light.bright * dot_p;
	clip_light(&hit->col);
	return (hit->col);
}

static t_b_rgb	get_ambient(t_hit *hit, t_a amb)
{
	t_b_rgb	amb_col;

	amb_col = ft_rgbtod(amb.rgb);
	hit->col.r *= amb_col.r * amb.amb_light;
	hit->col.g *= amb_col.g * amb.amb_light;
	hit->col.b *= amb_col.b * amb.amb_light;
	clip_light(&hit->col);
	return (hit->col);
}

uint32_t	ft_lighting(t_hit *hit, t_data *d, t_vect pixelv)
{
	t_vect	dir;
	t_hit	light_hit;

	dir = ft_vectnorm(ft_vectsub(d->light.pos, hit->point));
	get_ambient(hit, d->amb);
	if (ft_get_closest_hitpoint(ft_vectadd(hit->point, ft_vectmult(dir, 0.001)),
			dir, d, &light_hit))
		return (ft_rgba(hit->col));
	get_diffuse(hit, dir, d->light);
	get_specular(hit, dir, pixelv, d->light);
	return (ft_rgba(hit->col));
}
