/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 17:23:08 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// ~-~-~-~-~-~-~  Includes  ~-~-~-~-~-~-~ //

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGTH 900

# define MOVE_SPEED 1.5

# define PI 3.14159265358979323846264338327950288
# define PI_2 1.57079632679489661923132169163975144

// ~-~-~-~-~-~-~  Functions  ~-~-~-~-~-~-~ //

// ----- Parsing ----- //

bool	ft_init(t_data *data);
void	keyfunc(mlx_key_data_t keydata, void *param);

// ----- Vector functions ----- //

t_vect	ft_vectadd(t_vect v1, t_vect v2);
t_vect	ft_vectsub(t_vect v1, t_vect v2);
t_vect	ft_vectmult(t_vect v1, double num);
t_vect	ft_vectmult2(t_vect v1, t_vect v2);
t_vect	ft_vectdiv(t_vect v1, double num);
double	ft_vectmag(t_vect v1);
t_vect	ft_vectnorm(t_vect v1);
t_vect	ft_vectrot(t_vect v1, double angle, char axis);
void	ft_vectprint(t_vect v1);

#endif