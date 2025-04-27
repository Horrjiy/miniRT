/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:56:29 by tleister          #+#    #+#             */
/*   Updated: 2025/04/26 20:44:35 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/minirt.h"

t_vect	ft_vectcross(t_vect v1, t_vect v2)
{
	t_vect	ret;

	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return (ret);
}

double	ft_vectdot(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect	ft_vectrot(t_vect v1, double angle, char axis)
{
	t_vect	ret;

	ret = v1;
	if (axis == 'x')
	{
		ret.y = v1.y * cos(angle) - v1.z * sin(angle);
		ret.z = v1.y * sin(angle) + v1.z * cos(angle);
	}
	else if (axis == 'y')
	{
		ret.x = v1.x * cos(angle) + v1.z * sin(angle);
		ret.z = -v1.x * sin(angle) + v1.z * cos(angle);
	}
	else if (axis == 'z')
	{
		ret.x = v1.x * cos(angle) - v1.y * sin(angle);
		ret.y = v1.x * sin(angle) + v1.y * cos(angle);
	}
	return (ret);
}

double	ft_vectdist(t_coords p1, t_coords p2)
{
	return (ft_vectmag(ft_vectsub(p1, p2)));
}
