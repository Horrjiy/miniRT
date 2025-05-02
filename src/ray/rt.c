/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/05/02 16:58:06 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_set_cam_vect(t_data *d)
{
	d->cam.up.x = 0;
	d->cam.up.y = 1;
	d->cam.up.z = 0;
	d->cam.rigth = ft_vectnorm(ft_vectcross(d->cam.vec, d->cam.up));
	d->cam.up = ft_vectnorm(ft_vectcross(d->cam.vec, d->cam.rigth));
}

void	ft_render(void *param)
{
	static int		i = 0;
	t_data	*d;

	d = (t_data *)param;
	ft_set_cam_vect(d);
	if (i < 100)
	{
		ft_loop_pixel(d, i);
		i++;
	}
}
