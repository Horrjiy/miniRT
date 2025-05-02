/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:55 by tleister          #+#    #+#             */
/*   Updated: 2025/05/02 17:16:25 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vect	ft_get_camera_vect(int x, int y, t_data *d, int amount)
{
	t_vect	up;
	t_vect	rigth;

	amount = ft_map(amount, 100, -50, 50);
	rigth = ft_vectmult(d->cam.rigth, ft_map(x, W_WIDTH, -d->width, d->width));
	rigth = ft_vectmult(rigth, 1.0 + (double)amount / 1000.0);
	up = ft_vectmult(d->cam.up, ft_map(y, W_HEIGTH, -d->height, d->height));
	// up = ft_vectmult(up, 1.0 + (double)amount / 1000.0);
	return (ft_vectnorm(ft_vectadd(ft_vectmult(d->cam.vec, DIST), ft_vectadd(up,
					rigth))));
}

uint32_t	get_col(uint32_t col, uint8_t *avg, int amount)
{
	uint32_t	col_r;
	uint32_t	col_g;
	uint32_t	col_b;
	uint32_t	col_a;

	col_r = col >> 24 & 0xff;
	col_g = col >> 16 & 0xff;
	col_b = col >> 8 & 0xff;
	col_a = col & 0xff;
	col_r = (avg[0] * amount + col_r) / (amount + 1);
	col_g = (avg[1] * amount + col_g) / (amount + 1);
	col_b = (avg[2] * amount + col_b) / (amount + 1);
	col_a = (avg[3] * amount + col_a) / (amount + 1);
	return (col_r << 24 | col_g << 16 | col_b << 8 | col_a);
}

void	ft_loop_pixel(t_data *d, int am)
{
	int			y;
	int			x;
	uint32_t	col;
	t_hit		hit;
	t_vect		vec;

	y = 0;
	while (y < (int)d->img->height)
	{
		x = 0;
		while (x < (int)d->img->width)
		{
			vec = ft_get_camera_vect(x, y, d, am);
			if (ft_get_closest_hitpoint(d->cam.pos, vec, d, &hit))
				col = ft_lighting(&hit, d, vec);
			else
				col = 255 - (255 * d->amb.amb_light);
			if (am > 0)
				col = get_col(col, &d->img->pixels[(y * W_WIDTH + x) * 4], am);
			my_put_pixel(d->img, x, y, col);
			x++;
		}
		y++;
	}
}
