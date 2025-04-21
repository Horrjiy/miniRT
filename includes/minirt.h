/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 15:09:49 by tleister         ###   ########.fr       */
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

#endif