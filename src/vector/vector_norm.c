/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:41:08 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/25 17:55:54 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

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
