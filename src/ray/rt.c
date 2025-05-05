/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/05/05 12:17:29 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_render(void *param)
{
	static int	i = 0;
	static bool	antialiasing = false;
	t_data		*d;

	d = (t_data *)param;
	if (mlx_is_key_down(d->mlx, MLX_KEY_SPACE))
		antialiasing = !antialiasing;
	ft_printf("\033[?25l");
	if (d->start)
		i = 0;
	if (antialiasing || i == 0)
	{
		ft_printf("\033[2K\r %d samples", i + 1);
		ft_loop_pixel(d, i);
		i++;
		d->start = 0;
	}
}
