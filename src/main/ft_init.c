/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:39:39 by tleister          #+#    #+#             */
/*   Updated: 2025/04/30 18:44:51 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ft_init(t_data *data)
{
	double	ratio;
	double	theta;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "miniRT", true);
	if (!data->mlx)
		return (false);
	data->img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->img)
		return (mlx_terminate(data->mlx), false);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	ratio = ((double)W_WIDTH / (double)W_HEIGHT);
	theta = data->cam.fov * PI / 180.0;
	data->height = V_HEIGTH;
	data->width = ratio * sin(theta / 2) / sin(PI_2 / 2) * data->height;
	return (true);
}
