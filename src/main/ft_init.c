/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:39:39 by tleister          #+#    #+#             */
/*   Updated: 2025/04/23 11:01:20 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ft_init(t_data *data)
{
	data->mlx = mlx_init(W_WIDTH, W_HEIGTH, "miniRT", false);
	if (!data->mlx)
		return (false);
	data->img = mlx_new_image(data->mlx, W_WIDTH + 1, W_HEIGTH + 1);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	if (!data->img)
		return (mlx_terminate(data->mlx), false);
	return (true);
}
