/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:11:58 by tleister          #+#    #+#             */
/*   Updated: 2025/04/27 12:17:52 by tleister         ###   ########.fr       */
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

#include <stdarg.h>

void	ft_vectprint(char *str, ...)
{
	va_list	ap;
	int		i;
	t_vect	vect;
	t_b_rgb	col;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'g')
				printf("%g", va_arg(ap, double));
			else if (str[i] == 'd')
				printf("%d", va_arg(ap, int));
			else if (str[i] == 'x')
				printf("%x", va_arg(ap, int));
			else if (str[i] == 'X')
				printf("%X", va_arg(ap, int));
			else if (str[i] == 'p')
				printf("%p", va_arg(ap, void *));
			else if (str[i] == 's')
				printf("%s", va_arg(ap, char *));
			else if (str[i] == 'c')
				printf("%c", va_arg(ap, int));
			else if (str[i] == 'v')
			{
				vect = va_arg(ap, t_vect);
				printf("(%g | %g | %g)", vect.x, vect.y, vect.z);
			}
			else if (str[i] == 'l')
			{
				col = va_arg(ap, t_b_rgb);
				printf("r: %g, g: %g, b: %g", col.r, col.g, col.b);
			}
			else
				printf("\033[32mERROR\033[0m");
		}
		else
			printf("%c", str[i]);
		i++;
	}
}
