/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quad_eq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:53:06 by tleister          #+#    #+#             */
/*   Updated: 2025/04/30 14:03:19 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	ft_solve_quad_eq(double *abc)
{
	double	d;
	double t1;
	double t2;
	double	sqrt_disc;

	d = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (d < 0)
		return (-1);
	sqrt_disc = sqrtf(d);
	if (abc[0] == 0)
		return (-1);
	t1 = (-abc[1] - sqrt_disc) / (2 * abc[0]);
	t2 = (-abc[1] + sqrt_disc) / (2 * abc[0]);
	if(t1 < t2 && t1 > 0)
		return(t1);
	return (t2);
}
