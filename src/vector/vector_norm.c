/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:41:08 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/25 17:28:03 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

// 𝐀×𝐁 =⟨v1.y * v2.z - v2.y * v1.z, v2.x * v1.z - v1.x * v2.z, v1.x * v2.y - v2.x *v1.y⟩.

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
	return (v1.x * v2.x + v2.y * v2.y + v1.z * v2.z);
}

t_vect	ft_vectrot(t_vect v1, double angle, char axis)
{
	if (axis == 'x')
	{
		v1.y = v1.y * cos(angle) - v1.z * sin(angle);
		v1.z = v1.y * sin(angle) + v1.z * cos(angle);
	}
	else if (axis == 'y')
	{
		v1.x = v1.x * cos(angle) + v1.z * sin(angle);
		v1.z = -v1.x * sin(angle) + v1.z * cos(angle);
	}
	else if (axis == 'z')
	{
		v1.x = v1.x * cos(angle) - v1.y * sin(angle);
		v1.y = v1.x * sin(angle) + v1.y * cos(angle);
	}
	return (v1);
}

double	ft_vectmag(t_vect v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
}

t_vect	ft_vectnorm(t_vect v1)
{
	return (ft_vectdiv(v1, ft_vectmag(v1)));
}

void	ft_vectnorm2(t_coords *vec)
{
	double	magnitude;

	magnitude = ft_vectmag(*vec);
	vec->x /= magnitude;
	vec->y /= magnitude;
	vec->z /= magnitude;
}
