/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 16:35:52 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// ~-~-~-~-~-~-~  Includes  ~-~-~-~-~-~-~ //

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "structs.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGTH 900

# define WIDTH 1500
# define HEIGTH 900

// ~-~-~-~-~-~-~  Functions  ~-~-~-~-~-~-~ //

// ----- Parsing ----- //

bool	ft_init(t_data *data);
void	keyfunc(mlx_key_data_t keydata, void *param);

// ----- Vector functions ----- //
t_vect	ft_vectadd(t_vect v1, t_vect v2);
t_vect	ft_vectsub(t_vect v1, t_vect v2);
t_vect	ft_vectmult(t_vect v1, double num);
t_vect	ft_vectdiv(t_vect v1, double num);
double	ft_vectmag(t_vect v1);
t_vect	ft_vectnorm(t_vect v1);
void	ft_vectprint(t_vect v1);

#endif