/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/04/25 17:55:50 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

uint32_t	ft_rgba(t_rgb col)
{
	return (col.r << 24 | col.g << 16 | col.b << 8 | 0xff);
}

int			n[2];

bool	ft_sphere(t_obj *obj, t_vect vect, t_c cam, t_hit **d)
{
	t_sp	sp;
	double	b;
	double	c;
	double	in_sqrt;
	double	a;

	sp = obj->sphere;
	a = ft_vectdot(vect, vect);
	b = 2 * ft_vectdot(vect, cam.pos) - 2 * ft_vectdot(vect, sp.pos);
	c = ft_vectdot(cam.pos, cam.pos) + ft_vectdot(sp.pos, sp.pos) - 2 * ft_vectdot(cam.pos, sp.pos) - (sp.dia / 2) * (sp.dia / 2);
	in_sqrt = b * b - 4 * a * c;
	*d = malloc(sizeof(t_hit));
	if (in_sqrt < 0 || *d == NULL)
		return (free(*d), false);
	in_sqrt = sqrt(in_sqrt);
	(*d)->dist = (-b + in_sqrt) / (2 * a);
	if ((*d)->dist < 0 || ((*d)->dist > (-b - in_sqrt) / (2 * a) && (-b - in_sqrt) / (2 * a) > 0))
		(*d)->dist = (-b - in_sqrt) / (2 * a);
	if ((*d)->dist < 0)
		return (free(*d), *d = NULL, false);
	(*d)->col = sp.rgb;
	(*d)->obj = obj;
	(*d)->point = ft_vectadd(cam.pos, ft_vectmult(ft_vectnorm(vect), (*d)->dist));
	return (true);
}

bool (*g_intersects[shape_amount])(t_obj *, t_vect, t_c, t_hit **) = {&ft_sphere};

double	ft_map(int num, double omax, double newmin, double newmax)
{
	return (newmin + ((newmax - newmin) / omax) * num);
}

t_vect	ft_getray(int x, int y, t_c cam)
{
	t_vect	up;
	t_vect	rigth;

	up.x = 0;
	up.y = 1;
	up.z = 0;
	rigth = ft_vectnorm(ft_vectcross(cam.vec, up));
	up = ft_vectnorm(ft_vectcross(cam.vec, rigth));
	rigth = ft_vectmult(rigth, ft_map(x, W_WIDTH, -V_WIDTH, V_WIDTH));
	up = ft_vectmult(up, ft_map(y, W_HEIGTH, -V_HEIGTH, V_HEIGTH));
	return (ft_vectadd(ft_vectmult(cam.vec, DIST), ft_vectadd(up, rigth)));
}

t_hit	*ft_get_hit_point(t_vect vect, t_data *d)
{
	t_obj	*obj;
	t_hit	*point;
	double	min_dist;
	t_hit	*closest;

	point = NULL;
	closest = NULL;
	min_dist = INFINITY;
	obj = d->objects;
	if(n[0] == W_WIDTH / 2 && n[1] == W_HEIGTH)
	ft_vectprint("vect", vect);
	while (obj)
	{
		if (g_intersects[(int)obj->type](obj, vect, d->cam, &point))
		{
			if (min_dist > point->dist)
			{
				// printf("hit\n");
				free(closest);
				closest = point;
				min_dist = point->dist;
			}
		}
		obj = obj->next;
	}
	return (closest);
}

void	ft_render(t_data *data)
{
	int		y;
	int		x;
	t_hit	*hit;

	y = 0;
	while (y <= W_HEIGTH)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			n[0] = x;
			n[1] = y;
			hit = ft_get_hit_point(ft_getray(x, y, data->cam), data);
			if (hit)
				mlx_put_pixel(data->img, x, y, ft_rgba(hit->col));
			else
				mlx_put_pixel(data->img, x, y, 0xff);
			x++;
		}
		y++;
	}
}
