/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/05/02 13:48:19 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int				g_n[2];

static t_vect	ft_get_camera_vect(int x, int y, t_data *d)
{
	t_vect	up;
	t_vect	rigth;

	rigth = ft_vectmult(d->cam.rigth, ft_map(x, W_WIDTH, -d->width, d->width));
	up = ft_vectmult(d->cam.up, ft_map(y, W_HEIGTH, -d->height, d->height));
	return (ft_vectnorm(ft_vectadd(ft_vectmult(d->cam.vec, DIST), ft_vectadd(up,
					rigth))));
}

static	void ft_set_cam_vect(t_data *d)
{
	d->cam.up.x = 0;
	d->cam.up.y = 1;
	d->cam.up.z = 0;
	d->cam.rigth = ft_vectnorm(ft_vectcross(d->cam.vec, d->cam.up));
	d->cam.up = ft_vectnorm(ft_vectcross(d->cam.vec, d->cam.rigth));
}

void	ft_render(t_data *d)
{
	int		y;
	int		x;
	t_hit	hit;
	t_vect	vec;

	y = 0;
	ft_set_cam_vect(d);
	while (y < (int)d->img->height)
	{
		x = 0;
		while (x < (int)d->img->width)
		{
			vec = ft_get_camera_vect(x, y, d);
			if (ft_get_closest_hitpoint(d->cam.pos, vec, d, &hit))
			{
				hit.col = ft_lighting(&hit, d, vec);
				my_put_pixel(d->img, x, y, ft_rgba(hit.col));
			}
			else
				my_put_pixel(d->img, x, y, (255 - (255 * d->amb.amb_light)));
			x++;
		}
		y++;
	}
}
