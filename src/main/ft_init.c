/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:39:39 by tleister          #+#    #+#             */
/*   Updated: 2025/04/21 14:46:14 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	ft_init(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGTH, "miniRT", false);
	if (!data->mlx)
		return (false);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	if (!data->img)
		return (mlx_terminate(data->mlx), false);
	return (true);
}
