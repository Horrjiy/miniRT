/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:56:55 by tleister          #+#    #+#             */
/*   Updated: 2025/05/06 10:07:44 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vect	ft_get_camera_vect(int x, int y, t_data *d, int amount)
{
	t_vect	up;
	t_vect	right;
	double	dist;

	dist = DIST;
	dist = dist * (1.0 + (double)get_rand() / ((double)UINT32_MAX * 200.0));
	right = ft_vectmult(d->cam.right, ft_map(x, W_WIDTH, -d->width, d->width));
	if (amount)
		right = ft_vectmult(right, 1.0 + get_rand() / 858993459000.0);
	up = ft_vectmult(d->cam.up, ft_map(y, W_HEIGHT, -d->height, d->height));
	if (amount)
		up = ft_vectmult(up, 1.0 + get_rand() / 858993459000.0);
	return (ft_vectnorm(ft_vectadd(ft_vectmult(d->cam.vec, DIST), ft_vectadd(up,
					right))));
}

uint32_t	getcol(uint32_t col, uint8_t *avg, int amount)
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

static void	ft_progressbar(int x, int y)
{
	static int	all_pix;

	all_pix = W_WIDTH * W_HEIGHT;
	if (x != (W_WIDTH - 1))
		return ;
	printf("\x1b[2K");
	printf("Rendering progress:\t");
	printf("%.2f%%", (double)(W_WIDTH * y + x) / all_pix * 100);
	printf("\t--- %d / %d\n", (W_WIDTH * y + x) + 1, all_pix);
	printf("\033[A");
}

void	ft_loop_pixel(t_data *d, int am)
{
	int			y;
	int			x;
	uint32_t	col;
	t_hit		hit;
	t_vect		vec;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			vec = ft_get_camera_vect(x, y, d, am);
			if (ft_get_closest_hitpoint(d->cam.pos, vec, d, &hit))
				col = ft_lighting(&hit, d, vec);
			else
				col = 255 - (255 * d->amb.amb_light);
			if (am > 0)
				col = getcol(col, &d->img->pixels[(y * W_WIDTH + x) * 4], am);
			ft_progressbar(x, y);
			my_put_pixel(d->img, x, y, col);
			x++;
		}
		y++;
	}
}
