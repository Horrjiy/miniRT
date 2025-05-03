/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:39:39 by tleister          #+#    #+#             */
/*   Updated: 2025/05/03 10:30:16 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_set_cam_vect(t_data *d)
{
	d->cam.up.x = 0;
	d->cam.up.y = 1;
	d->cam.up.z = 0;
	d->cam.right = ft_vectnorm(ft_vectcross(d->cam.vec, d->cam.up));
	d->cam.up = ft_vectnorm(ft_vectcross(d->cam.vec, d->cam.right));
}

bool	ft_init(t_data *data)
{
	double	ratio;
	double	theta;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(W_WIDTH, W_HEIGTH, "miniRT", true);
	if (!data->mlx)
		return (false);
	data->img = mlx_new_image(data->mlx, W_WIDTH + 1, W_HEIGTH + 1);
	if (!data->img)
		return (mlx_terminate(data->mlx), false);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	ratio = ((double)W_WIDTH / (double)W_HEIGTH);
	theta = data->cam.fov * PI / 180.0;
	data->height = V_HEIGTH;
	data->width = ratio * sin(theta / 2) / sin(PI_2 / 2) * data->height;
	ft_set_cam_vect(data);
	return (true);
}
