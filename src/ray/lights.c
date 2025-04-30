/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:23:01 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/30 18:57:18 by tleister         ###   ########.fr       */
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

static t_b_rgb	ft_mix_color(t_hit *hit, t_vect light_dir, t_data *d)
{
	t_b_rgb	light_col;
	double	dot_p;

	dot_p = ft_vectdot(light_dir, hit->normal);
	light_col = ft_get_lightcolor(ft_rgbtod(d->light.rgb), d->light.bright
			* dot_p);
	hit->col.r += light_col.r * hit->col.r;
	hit->col.g += light_col.g * hit->col.g;
	hit->col.b += light_col.b * hit->col.b;
	if (hit->col.r > 1)
		hit->col.r = 1;
	if (hit->col.g > 1)
		hit->col.g = 1;
	if (hit->col.b > 1)
		hit->col.b = 1;
	return (hit->col);
}

t_b_rgb	ft_lighting(t_hit *hit, t_data *d)
{
	t_vect	dir;
	t_hit	light_hit;
	t_b_rgb	amb_col;

	dir = ft_vectnorm(ft_vectsub(d->light.pos, hit->point));
	amb_col = ft_get_lightcolor(ft_rgbtod(d->amb.rgb), d->amb.amb_light);
	hit->col.r *= amb_col.r;
	hit->col.g *= amb_col.g;
	hit->col.b *= amb_col.b;
	if (ft_get_closest_hitpoint(ft_vectadd(hit->point, ft_vectmult(dir, 0.001)),
			dir, d, &light_hit))
		return (ft_get_lightcolor(hit->col, d->amb.amb_light));
	return (ft_mix_color(hit, dir, d));
}
