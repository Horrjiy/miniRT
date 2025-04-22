/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/22 17:39:17 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// ~-~-~-~-~-~-~-~-~  includes  ~-~-~-~-~-~-~-~-~ //

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGTH 900

# define WIDTH 1500
# define HEIGTH 900

// ~-~-~-~-~-~-~-~-~  functions  ~-~-~-~-~-~-~-~-~ //

// ----- parsing ----- //

void	ft_analyze(t_data *data);
void	init_ambient(t_data *data, char *line);
void	init_light(t_data *data, char *line);
void	init_camera(t_data *data, char *line);
void	init_sphere(t_data *data, char *line);
void	init_plane(t_data *data, char *line);
void	init_cylinder(t_data *data, char *line);
double	ft_atodb(char *str);

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

// ----- free & error ----- //
void	freearr(char **strarr);
void	free_data(t_data *data);
void	ft_parserr(t_data *data, int exnum);
void	wr_err(char *msg);

#endif