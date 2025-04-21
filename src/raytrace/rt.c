/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:15 by tleister          #+#    #+#             */
/*   Updated: 2025/04/21 19:10:50 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

ft_map(int num, int omax, int newmin, int newmax)
{
	return (newmin + ((newmax - newmin) / omax) * num);
}

t_vect	ft_getrayvect(int x, int y, t_c cam)
{
	t_vect	up;
	t_vect	rigth;

	up.x = 0;
	up.y = 0;
	up.y = 1;
	rigth = ft_vectmult(ft_vectnorm(ft_vectcross(cam.vec, up)), ft_map(x,
				W_WIDTH, -V_WIDTH, V_WIDTH));
	up = ft_vectmult(ft_vectnorm(ft_vectcross(cam.vec, rigth)), ft_map(y,
				W_HEIGTH, -V_HEIGTH, V_HEIGTH));
	return (ft_vectadd(cam.vec, ft_vectadd(up, rigth)));
}

void	ft_render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < W_HEIGTH)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			ft_vectprint(ft_getrayvect(x, y, data->cam));
			x++;
		}
		y++;
	}
}
