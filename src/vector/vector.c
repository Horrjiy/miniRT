/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:11:58 by tleister          #+#    #+#             */
/*   Updated: 2025/04/22 12:06:58 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_vect	ft_vectadd(t_vect v1, t_vect v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vect	ft_vectsub(t_vect v1, t_vect v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vect	ft_vectmult(t_vect v1, double num)
{
	v1.x *= num;
	v1.y *= num;
	v1.z *= num;
	return (v1);
}

t_vect	ft_vectdiv(t_vect v1, double num)
{
	v1.x /= num;
	v1.y /= num;
	v1.z /= num;
	return (v1);
}

void	ft_vectprint(char *str, t_vect v1)
{
	printf("%s:	x: %g, y: %g, z: %g\n", str, v1.x, v1.y, v1.z);
}
