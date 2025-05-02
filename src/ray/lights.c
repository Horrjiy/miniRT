/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:23:01 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/02 14:55:21 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// Calculates the actual color of the light out of the color and brigthness
static t_b_rgb	ft_get_lightcolor(t_b_rgb light, double brightness)
{
	t_b_rgb	c;

	if (brightness > 1)
		brightness = 1;
	else if (brightness < 0)
		brightness = 0;
	c.r = light.r * brightness;
	c.g = light.g * brightness;
	c.b = light.b * brightness;
	return (c);
}

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

// l_n = ft_v3_dotprod(light_dir, &rec->n);
// ft_v3_init(&tmp, rec->n.x, rec->n.y, rec->n.z);
// ft_v3_scalar_ip(&tmp, 2 * l_n);
// ft_v3_sub_ip(&tmp, light_dir);
// ft_v3_init(&rev_ray, rec->ray->dir->x, rec->ray->dir->y, rec->ray->dir->z);

static t_b_rgb	phong_lighting(t_hit *hit, t_vect light_dir, t_data *d,
		t_vect pixelv)
{
	t_b_rgb	light;
	double	dot_p;
	double	l_n;
	t_vect	temp;

	dot_p = ft_vectdot(light_dir, hit->normal);
	light = ft_get_lightcolor(ft_rgbtod(d->light.rgb), d->light.bright * dot_p);
	dot_p = ft_vectdot(light_dir, pixelv);
	hit->col.r += light.r * hit->col.r;
	hit->col.g += light.g * hit->col.g;
	hit->col.b += light.b * hit->col.b;
	clip_light(&hit->col);
	l_n = ft_vectdot(light_dir, hit->normal);
	temp = ft_vectmult(hit->normal, 2 * l_n);
	temp = ft_vectsub(temp, light_dir);
	dot_p = ft_vectdot(temp, ft_vectmult(pixelv, -1));
	light = ft_get_lightcolor(ft_rgbtod(d->light.rgb), d->light.bright
			* pow(dot_p, 5));
	hit->col.r += light.r;
	hit->col.g += light.g;
	hit->col.b += light.b;
	clip_light(&hit->col);
	return (hit->col);
}

t_b_rgb	ft_lighting(t_hit *hit, t_data *d, t_vect pixelv)
{
	t_vect	dir;
	t_hit	light_hit;
	t_b_rgb	amb_col;

	dir = ft_vectnorm(ft_vectsub(d->light.pos, hit->point));
	amb_col = ft_get_lightcolor(ft_rgbtod(d->amb.rgb), d->amb.amb_light);
	hit->col.r *= amb_col.r;
	hit->col.g *= amb_col.g;
	hit->col.b *= amb_col.b;
	clip_light(&hit->col);
	if (ft_get_closest_hitpoint(ft_vectadd(hit->point, ft_vectmult(dir, 0.001)),
			dir, d, &light_hit))
		return (ft_get_lightcolor(hit->col, d->amb.amb_light));
	return (phong_lighting(hit, dir, d, pixelv));
}
