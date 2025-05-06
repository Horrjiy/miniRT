/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:05:19 by tleister          #+#    #+#             */
/*   Updated: 2025/05/06 10:48:01 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

// ~-~-~-~-~-~-~  coords and colors  ~-~-~-~-~-~-~ //

typedef struct s_coord
{
	double					x;
	double					y;
	double					z;
} t_coords,	t_vect;

typedef struct s_rgbcolor
{
	unsigned char			r;
	unsigned char			g;
	unsigned char			b;
}							t_rgb;

typedef struct s_color_brigthness
{
	double					r;
	double					g;
	double					b;
}							t_b_rgb;

// ~-~-~-~-~-~-~ scene elements ~-~-~-~-~-~-~ //

typedef struct s_ambient
{
	double					amb_light;
	t_rgb					rgb;
}							t_a;

typedef struct s_camera
{
	t_vect					right;
	t_vect					up;
	t_coords				pos;
	t_coords				vec;
	double					fov;
}							t_c;

typedef struct s_light
{
	t_coords				pos;
	double					bright;
	t_rgb					rgb;
}							t_l;

typedef struct s_sphere
{
	t_coords				pos;
	double					dia;
	t_rgb					rgb;
}							t_sp;

typedef struct s_plane
{
	t_coords				pos;
	t_coords				nvec;
	t_rgb					rgb;
}							t_pl;

typedef struct s_cylinder
{
	t_coords				pos;
	t_coords				vec;
	double					dia;
	double					h;
	t_rgb					rgb;
}							t_cy;

typedef struct s_cone
{
	t_coords				pos;
	t_coords				vec;
	double					dia;
	double					h;
	t_rgb					rgb;
}							t_co;

typedef struct s_triangle
{
	t_coords				pt_a;
	t_coords				pt_b;
	t_coords				pt_c;
	t_rgb					rgb;
}							t_tr;

// ~-~-~-~-~-~-~ management ~-~-~-~-~-~-~ //

typedef enum e_status
{
	sphere,
	plane,
	cylinder,
	cone,
	triangle,
	shape_amount
}							t_status;

typedef struct s_scene_objects
{
	t_status				type;
	struct s_scene_objects	*next;
	union
	{
		t_sp				sphere;
		t_pl				plane;
		t_cy				cylinder;
		t_co				cone;
		t_tr				triang;
	};
}							t_obj;

typedef struct s_hitpoint
{
	t_obj					*obj;
	t_vect					normal;
	t_b_rgb					col;
	t_coords				point;
	double					dist;
}							t_hit;

typedef struct s_data
{
	mlx_t					*mlx;
	mlx_image_t				*img;
	t_obj					*objects;
	t_c						cam;
	t_a						amb;
	t_l						light;
	int						all_surrnd[3];
	char					*str;
	char					**scene;
	double					width;
	double					height;
	bool					start;
}							t_data;

#endif
