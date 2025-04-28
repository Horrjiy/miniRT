/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizefunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:52:08 by tleister          #+#    #+#             */
/*   Updated: 2025/04/25 12:12:27 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_resizefunc(int32_t width, int32_t height, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	mlx_delete_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, width, height);
	if (!d->mlx)
		ft_parserr(d, ENOMEM);
	mlx_image_to_window(d->mlx, d->img, 0, 0);
	ft_render(d);
}
