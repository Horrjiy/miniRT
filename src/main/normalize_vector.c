/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:25:54 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 16:26:06 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_normalize_vector(t_coords *vec)
{
	double magnitude;

	magnitude = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
	vec->x /= magnitude;
	vec->y /= magnitude;
	vec->z /= magnitude;
}