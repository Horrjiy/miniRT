/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/05 16:46:59 by tleister         ###   ########.fr       */
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
// # define W_HEIGHT 900
// # define W_WIDTH 320
// # define W_HEIGHT 180
# define W_WIDTH 1280
// # define W_WIDTH 640
// # define W_WIDTH 320
# define W_HEIGHT 720
// # define W_HEIGHT 360
// # define W_HEIGHT 180
# define V_WIDTH 2.0
// # define V_HEIGTH 3.333333333333333333333 //  W_HEIGHT / W_WIDTH * V_WIDTH
# define V_HEIGTH 1.125 //  W_HEIGHT / W_WIDTH * V_WIDTH

# define MOVE_SPEED 0.5
# define DIST 3.0

# define PI 3.14159265358979323846264338327950288
# define PI_2 1.57079632679489661923132169163975144

# define COORD_V 0
# define COORD_W 1
# define COORD_U 2

// ~-~-~-~-~-~-~-~-~  functions  ~-~-~-~-~-~-~-~-~ //

// ----- parsing ----- //

void			ft_analyze(t_data *data, int fd);
void			init_ambient(t_data *data, char *line);
void			init_light(t_data *data, char *line);
void			init_camera(t_data *data, char *line);
void			init_sphere(t_data *data, char *line);
void			init_plane(t_data *data, char *line);
void			init_cylinder(t_data *data, char *line);
void			init_triangle(t_data *data, char *line);
void			init_cone(t_data *data, char *line);
void			split_line(t_data *data, char **line);
void			ft_node_addback(t_obj **head, t_obj *node);
t_obj			*init_object_node(int type, t_data *data);
t_obj			*ft_lastnode(t_obj *head);
double			ft_atodb(char *str);
int				ft_safe_atoi(char *str, t_data *data);
unsigned char	ft_safe_atouc(char *str, t_data *data);
size_t			ft_comlen(const char *s);

double			ft_convert_double(t_data *data);
t_rgb			ft_convert_rgb(t_data *data);
t_coords		ft_convert_coords(t_data *data);

// ----- rendering ----- //

// calls ft_loop_pixel more often for antialiasing
void			ft_render(void *param);

// goes througth all pixels of the window and sets them correctly
void			ft_loop_pixel(t_data *d, int amount);

// gets the closest hit point of the line defined by origin and dir with any object
bool			ft_get_closest_hitpoint(t_coords or, t_vect dir, t_data *d,
					t_hit *closest);

// initializes the data
bool			ft_init(t_data *data);

// checks for movement keys and sets vaues accordingly
void			ft_keyfunc(mlx_key_data_t keydata, void *param);

// calculates a pseudo random number
double			get_rand(void);

// closes the window if esc is pressed
void			esc(mlx_key_data_t keydata, void *param);

// -------- objects --------- //

bool			ft_sphere(t_obj *obj, t_coords or, t_vect dir, t_hit *point);
bool			ft_plane(t_obj *obj, t_vect supv, t_vect dirv, t_hit *point);
bool			ft_cylinder(t_obj *obj, t_coords or, t_vect dir, t_hit *point);
bool			ft_cone(t_obj *obj, t_coords or, t_vect dir, t_hit *point);
bool			ft_triangle(t_obj *obj, t_vect supv, t_vect dirv, t_hit *point);

// -------- light --------- //

// convert t_rgb to t_b_rgb
t_b_rgb			ft_rgbtod(t_rgb col);

// converts the t_b_rgb to and rgba integer format
uint32_t		ft_rgba(t_b_rgb col);

// calculates the color for lit points
uint32_t		ft_lighting(t_hit *hit, t_data *d, t_vect cam_vect);

// maps a number within a range into another range
double			ft_map(int num, double oldmax, double newmin, double newmax);

// puts only a pixel if x/y are inside the image
void			my_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
					uint32_t color);

double			ft_solve_quad_eq(double *abc);

// ----- Vector functions ----- //

t_vect			ft_vectadd(t_vect v1, t_vect v2);
t_vect			ft_vectsub(t_vect v1, t_vect v2);
t_vect			ft_vectmult(t_vect v1, double num);
t_vect			ft_vectcross(t_vect v1, t_vect v2);
t_vect			ft_vectdiv(t_vect v1, double num);
double			ft_vectmag(t_vect v1);
t_vect			ft_vectnorm(t_vect v1);

// rotates a vector around an axis
// @param v1 the vector
// @param angle the rotation angle in radiant
// @param axis the x, y or z axis
void			ft_vectnorm2(t_coords *vec);
t_vect			ft_vectrot(t_vect v1, double angle, char axis);
void			ft_vectprint(char *str, ...);
double			ft_vectdot(t_vect v1, t_vect v2);
double			ft_vectdist(t_coords p1, t_coords p2);

// ----- free & error ----- //

void			freearr(char **strarr);
void			free_data(t_data *data);
void			freen(char **str);

void			ft_parserr(t_data *data, int exnum);

void			wr_err(char *msg);

#endif