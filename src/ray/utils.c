/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:29:26 by tleister          #+#    #+#             */
/*   Updated: 2025/04/29 15:37:27 by mpoplow          ###   ########.fr       */
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
