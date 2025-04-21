/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 14:47:13 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// ~-~-~-~-~-~-~  Includes  ~-~-~-~-~-~-~ //

# include "../libft/libft.h"
# include "MLX42.h"
# include <stdbool.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGTH 900

// ~-~-~-~-~-~-~  Definitions and structs; ~-~-~-~-~-~-~ //

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_data;

// ~-~-~-~-~-~-~  Functions  ~-~-~-~-~-~-~ //

bool			ft_argvcheck(int argc, char **argv);
bool			ft_init(t_data *data);
void			keyfunc(mlx_key_data_t keydata, void *param);

#endif