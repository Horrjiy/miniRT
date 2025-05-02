/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:29:26 by tleister          #+#    #+#             */
/*   Updated: 2025/05/02 11:23:48 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	ft_map(int num, double omax, double newmin, double newmax)
{
	return (newmin + ((newmax - newmin) / omax) * num);
}

void	my_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	if (x > 0 && x < image->width && y > 0 && y < image->height)
		mlx_put_pixel(image, x, y, color);
}

uint32_t	ft_rgba(t_b_rgb col)
{
	return ((unsigned char)(col.r * 255) << 24 | (unsigned char)(col.g
			* 255) << 16 | (unsigned char)(col.b * 255) << 8 | 0xff);
}

t_b_rgb	ft_rgbtod(t_rgb col)
{
	t_b_rgb	c;

	c.r = (double)col.r / 255;
	c.g = (double)col.g / 255;
	c.b = (double)col.b / 255;
	return (c);
}

double	ft_solve_quad_eq(double *abc)
{
	double	d;
	double	t1;
	double	t2;
	double	sqrt_disc;

	d = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (d < 0)
		return (-1);
	sqrt_disc = sqrtf(d);
	if (abc[0] == 0)
		return (-1);
	t1 = (-abc[1] - sqrt_disc) / (2 * abc[0]);
	t2 = (-abc[1] + sqrt_disc) / (2 * abc[0]);
	if (t1 < t2 && t1 > 0)
		return (t1);
	return (t2);
}
