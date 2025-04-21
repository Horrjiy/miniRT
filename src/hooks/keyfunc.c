/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:38:14 by tleister          #+#    #+#             */
/*   Updated: 2025/04/21 16:32:17 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	keyfunc(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
}
