/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/04/27 12:44:56 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

uint32_t	ft_rgba(t_b_rgb col)
{
	return ((unsigned char)(col.r * 255) << 24 | (unsigned char)(col.g
			* 255) << 16 | (unsigned char)(col.b * 255) << 8 | 0xff);
}

t_b_rgb	ft_convertrgb(t_rgbcolor col)
{
	t_b_rgb	c;

	c.r = (double)col.r / 255;
	c.g = (double)col.g / 255;
	c.b = (double)col.b / 255;
	return (c);
}

double	ft_map(int num, double omax, double newmin, double newmax)
{
	return (newmin + ((newmax - newmin) / omax) * num);
}

void	my_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	if (x > 0 && x < image->width && y > 0 && y < image->height)
		mlx_put_pixel(image, x, y, color);
}

int				g_n[2];

static t_vect	ft_get_camera_ray(int x, int y, t_c cam)
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
	return (ft_vectnorm(ft_vectadd(ft_vectmult(cam.vec, DIST), ft_vectadd(up, rigth))));
}

t_hit	*ft_get_closest_hitpoint(t_coords or, t_vect dir, t_data *d)
{
	t_obj	*obj;
	t_hit	*point;
	double	min_dist;
	t_hit	*closest;

	t_hit *(*g_intersects[shape_amount])(t_obj *, t_coords, t_vect,
			t_data *) = {&ft_sphere};
	closest = NULL;
	min_dist = INFINITY;
	obj = d->objects;
	while (obj)
	{
		point = g_intersects[(int)obj->type](obj, or, dir, d);
		if (point)
		{
			if (min_dist > point->dist)
			{
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
	while (y < (int)data->img->height)
	{
		x = 0;
		while (x < (int)data->img->width)
		{
			g_n[0] = x;
			g_n[1] = y;
			hit = ft_get_closest_hitpoint(data->cam.pos, ft_get_camera_ray(x, y,
						data->cam), data);
			if (hit)
			{
				// printf("\n");
				// printf("%d",ft_rgba(hit->col));
				hit->col = ft_check_ligth(hit, data);
				my_put_pixel(data->img, x, y, ft_rgba(hit->col));
				free(hit);
			}
			else
				my_put_pixel(data->img, x, y, 0xff);
			x++;
		}
		y++;
	}
}
