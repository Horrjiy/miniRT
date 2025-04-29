/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/04/29 19:04:30 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int				g_n[2];

static t_vect	ft_get_camera_vect(int x, int y, t_data *d)
{
	t_vect	up;
	t_vect	rigth;

	up.x = 0;
	up.y = 1;
	up.z = 0;
	rigth = ft_vectnorm(ft_vectcross(d->cam.vec, up));
	up = ft_vectnorm(ft_vectcross(d->cam.vec, rigth));
	rigth = ft_vectmult(rigth, ft_map(x, W_WIDTH, -d->width, d->width));
	up = ft_vectmult(up, ft_map(y, W_HEIGTH, -d->height, d->height));
	return (ft_vectnorm(ft_vectadd(ft_vectmult(d->cam.vec, DIST), ft_vectadd(up, rigth))));
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
			hit = ft_get_closest_hitpoint(data->cam.pos, ft_get_camera_vect(x, y,
						data), data);
			if (hit)
			{
				hit->col = ft_lighting(hit, data);
				my_put_pixel(data->img, x, y, ft_rgba(hit->col));
				free(hit);
			}
			else
				my_put_pixel(data->img, x, y, (255 - (255 * data->amb.amb_light)));
			x++;
		}
		y++;
	}
}
