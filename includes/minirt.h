/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 15:34:22 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// ~-~-~-~-~-~-~  Includes  ~-~-~-~-~-~-~ //

# include "../libft/libft.h"
# include "MLX42.h"
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

bool	ft_argvcheck(int argc, char **argv);
bool	ft_init(t_data *data);
void	keyfunc(mlx_key_data_t keydata, void *param);
bool	ft_argvcheck(int argc, char **argv);
void	ft_normalize_vector(t_coords *vec);

//	vectfuncts
t_vect	ft_vectadd(t_vect v1, t_vect v2);
t_vect	ft_vectsub(t_vect v1, t_vect v2);
t_vect	ft_vectmult(t_vect v1, double num);
t_vect	ft_vectdiv(t_vect v1, double num);
double	ft_vectmag(t_vect v1);
t_vect	ft_vectnorm(t_vect v1);
# define ft_pointprint ft_vectprint;
void	ft_vectprint(t_vect v1);

#endif