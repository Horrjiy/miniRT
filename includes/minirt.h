/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 16:18:38 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// ~-~-~-~-~-~-~  Includes  ~-~-~-~-~-~-~ //

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGTH 900

# define WIDTH 1500
# define HEIGTH 900

// ~-~-~-~-~-~-~  Definitions and structs  ~-~-~-~-~-~-~ //

typedef struct s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coords;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgbcolor;

// ~-~-~-~-~-~-~ Scene elements ~-~-~-~-~-~-~ //

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
}					t_data;
typedef struct s_ambient
{
	double			amb_light;
	t_rgbcolor		rgb;

}					t_a;

typedef struct s_camera
{
	t_coords		pos;
	t_coords		vec;
	int				fov;
}					t_c;

typedef struct s_light
{
	t_coords		pos;
	double			bright;
	t_rgbcolor		rgb;
}					t_l;

typedef struct s_sphere
{
	t_coords		pos;
	double			dia;
	t_rgbcolor		rgb;
}					t_sp;

typedef struct s_plane
{
	t_coords		pos;
	t_coords		nvec;
	t_rgbcolor		rgb;
}					t_pl;

typedef struct s_cylinder
{
	t_coords		pos;
	t_coords		vec;
	double			dia;
	double			h;
	t_rgbcolor		rgb;

}					t_cy;

typedef enum e_status
{
	amb,
	cam,
	light,
	sphere,
	plane,
	cylinder
}					t_status;

typedef struct s_all
{
	t_status		type;
	struct s_all	*next;
	union
	{
		t_a			amb;
		t_c			cam;
		t_l			light;
		t_sp		sphere;
		t_pl		plane;
		t_cy		cylinder;
	};
}					t_all;

// ~-~-~-~-~-~-~  Functions  ~-~-~-~-~-~-~ //

// ----- Parsing ----- //
void				ft_normalize_vector(t_coords *vec);


bool				ft_init(t_data *data);
void				keyfunc(mlx_key_data_t keydata, void *param);

#endif