/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/25 12:38:42 by tleister         ###   ########.fr       */
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

// ~-~-~-~-~-~-~-~-~  macros  ~-~-~-~-~-~-~-~-~ //

// # define W_WIDTH 1500
// # define W_HEIGTH 900
# define W_WIDTH 600
# define W_HEIGTH 500
# define V_WIDTH 2
// # define V_HEIGTH 3.333333333333333333333 //  W_HEIGTH / W_WIDTH * V_WIDTH
# define V_HEIGTH 1.666666666666666666666 //  W_HEIGTH / W_WIDTH * V_WIDTH

# define MOVE_SPEED 0.5
# define DIST 3

# define PI 3.14159265358979323846264338327950288
# define PI_2 1.57079632679489661923132169163975144

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

// ----- rendering ----- //

// goes througth all pixels of the window and sets them correctly
void	ft_render(t_data *data);

bool	ft_init(t_data *data);
// checks for movement keys and sets vaues accordingly
void	ft_keyfunc(void *param);
// resizes the image if the window is resized
void	ft_resizefunc(int32_t width, int32_t height, void *param);
// closes the window if esc is pressed
void	esc(mlx_key_data_t keydata, void *param);

// ----- Vector functions ----- //

t_vect	ft_vectadd(t_vect v1, t_vect v2);
t_vect	ft_vectsub(t_vect v1, t_vect v2);
t_vect	ft_vectmult(t_vect v1, double num);
t_vect	ft_vectcross(t_vect v1, t_vect v2);
t_vect	ft_vectdiv(t_vect v1, double num);
double	ft_vectmag(t_vect v1);
t_vect	ft_vectnorm(t_vect v1);
// rotates a vector around an axis
// @param v1 the vector
// @param angle the rotation angle in radiant
// @param axis the x, y or z axis
t_vect	ft_vectrot(t_vect v1, double angle, char axis);
void	ft_vectprint(char *str, t_vect v1);
double	ft_vectdot(t_vect v1, t_vect v2);

// ----- free & error ----- //

void	freearr(char **strarr);
void	free_data(t_data *data);
// frees data, prints an error message and exits the program
void	ft_parserr(t_data *data, int exnum);
// Writes "Error\n" followed by the specified error message on fd 2.
void	wr_err(char *msg);

#endif