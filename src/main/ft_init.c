/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:39:39 by tleister          #+#    #+#             */
/*   Updated: 2025/04/29 15:20:36 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ft_init(t_data *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(W_WIDTH, W_HEIGTH, "miniRT", true);
	if (!data->mlx)
		return (false);
	data->img = mlx_new_image(data->mlx, W_WIDTH + 1, W_HEIGTH + 1);
	if (!data->img)
		return (mlx_terminate(data->mlx), false);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	return (true);
}
