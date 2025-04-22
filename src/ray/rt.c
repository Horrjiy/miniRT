/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/04/22 17:56:43 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

uint32_t	ft_rgba(t_rgbcolor col)
{
	return (col.r << 24 | col.g << 16 | col.b << 8 | 0xff);
}

bool	ft_spere(t_obj *obj, t_vect vect, t_c cam, t_hit **d)
{
	t_sp	sp;
	double	a;
	double	b;
	double	c;
	double	in_sqrt;

	sp = obj->sphere;
	a = ft_vectdot(vect, vect);
	b = 2 * (ft_vectdot(vect, cam.pos) - ft_vectdot(vect, sp.pos));
	c = sp.dia / 2 - ft_vectdot(cam.pos, cam.pos) - ft_vectdot(sp.pos, sp.pos)
		- 2 * ft_vectdot(cam.pos, sp.pos);
	in_sqrt = b * b - 4 * a * c;
	*d = malloc(sizeof(t_hit));
	if (in_sqrt < 0 || !*d)
		return (free(d), false);
	in_sqrt = sqrt(in_sqrt);
	(*d)->dist = (-b + in_sqrt) / 2 * a;
	if ((*d)->dist < 0 || (*d)->dist > (-b - in_sqrt) / 2 * a)
		(*d)->dist = (-b - in_sqrt) / 2 * a;
	if ((*d)->dist < 0)
		return (free(*d), *d = NULL, false);
	(*d)->col = sp.rgb;
	(*d)->obj = obj;
	(*d)->point = ft_vectadd(cam.pos, ft_vectmult(vect, (*d)->dist));
	return (true);
}

bool		(*g_intersects[shape_amount])(t_obj *, t_vect, t_c, t_hit **) = {&ft_spere};

double	ft_map(int num, double omax, double newmin, double newmax)
{
	return (newmin + ((newmax - newmin) / omax) * num);
}

t_vect	ft_getrayvect(int x, int y, t_c cam)
{
	t_vect	up;
	t_vect	rigth;

	up.x = 0;
	up.y = 0;
	up.z = 1;
	rigth = ft_vectmult(ft_vectnorm(ft_vectcross(cam.vec, up)), ft_map(x,
				W_WIDTH, -V_WIDTH, V_WIDTH));
	up = ft_vectmult(ft_vectnorm(ft_vectcross(cam.vec, rigth)), ft_map(y,
				W_HEIGTH, -V_HEIGTH, V_HEIGTH));
	return (ft_vectnorm(ft_vectadd(cam.vec, ft_vectadd(up, rigth))));
}

t_hit	*ft_get_hit_point(t_vect vect, t_data *d)
{
	t_obj	*obj;
	t_hit	*point;
	double	min_dist;
	t_obj	*closest;

	point = NULL;
	closest = NULL;
	min_dist = INFINITY;
	obj = d->objects;
	while (obj)
	{
		if (g_intersects[(int)obj->type](obj, vect, d->cam, &point))
		{
			if (min_dist < point->dist)
			{
				closest = obj;
				min_dist = point->dist;
			}
		}
		obj = obj->next;
	}
	return (point);
}

void	ft_render(t_data *data)
{
	int		y;
	int		x;
	t_hit	*point;

	y = 0;
	while (y < W_HEIGTH)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			point = ft_get_hit_point(ft_getrayvect(x, y, data->cam), data);
			if (point)
				mlx_put_pixel(data->img, x, y, ft_rgba(point->col));
			x++;
		}
		y++;
	}
}
