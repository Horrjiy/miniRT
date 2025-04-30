/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/04/30 19:15:15 by mpoplow          ###   ########.fr       */
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
	up = ft_vectmult(up, ft_map(y, W_HEIGHT, -d->height, d->height));
	return (ft_vectnorm(ft_vectadd(ft_vectmult(d->cam.vec, DIST), ft_vectadd(up,
					rigth))));
}

static void	ft_progressbar(int x, int y)
{
	static int all_pix = W_WIDTH * W_HEIGHT;
	if(x != (W_WIDTH - 1))
		return;
	printf("\x1b[A\x1b[2K");
	printf("Rendering progress:\t");
	printf("%.2f%%", (double)(W_WIDTH * y + x) / all_pix * 100);
	printf("\t--- %d / %d\n", (W_WIDTH * y + x) + 1, all_pix);
}

void	ft_render(t_data *data)
{
	int		y;
	int		x;
	t_hit	hit;

	y = 0;
	while (y < (int)data->img->height)
	{
		x = 0;
		while (x < (int)data->img->width)
		{
			if (ft_get_closest_hitpoint(data->cam.pos, ft_get_camera_vect(x, y,
						data), data, &hit))
			{
				hit.col = ft_lighting(&hit, data);
				my_put_pixel(data->img, x, y, ft_rgba(hit.col));
			}
			else
				my_put_pixel(data->img, x, y, (255 - (255
								* data->amb.amb_light)));
			ft_progressbar(x, y);
			x++;
		}
		y++;	
	}
}
