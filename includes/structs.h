/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:05:19 by tleister          #+#    #+#             */
/*   Updated: 2025/04/21 15:53:20 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

// ~-~-~-~-~-~-~  Coords and colors  ~-~-~-~-~-~-~ //

typedef struct s_coord
{
	double					x;
	double					y;
	double					z;
} t_coords, t_vect;

typedef struct s_rgb
{
	unsigned char			r;
	unsigned char			g;
	unsigned char			b;
}							t_rgbcolor;

// ~-~-~-~-~-~-~ Scene elements ~-~-~-~-~-~-~ //

typedef struct s_ambient
{
	double					amb_light;
	t_rgbcolor				rgb;

}							t_a;

typedef struct s_camera
{
	t_coords				pos;
	t_coords				vec;
	int						fov;
}							t_c;

typedef struct s_light
{
	t_coords				pos;
	double					bright;
	t_rgbcolor				rgb;
}							t_l;

typedef struct s_sphere
{
	t_coords				pos;
	double					dia;
	t_rgbcolor				rgb;
}							t_sp;

typedef struct s_plane
{
	t_coords				pos;
	t_coords				nvec;
	t_rgbcolor				rgb;
}							t_pl;

typedef struct s_cylinder
{
	t_coords				pos;
	t_coords				vec;
	double					dia;
	double					h;
	t_rgbcolor				rgb;
}							t_cy;

typedef enum e_status
{
	sphere,
	plane,
	cylinder
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
	};
}							t_obj;

typedef struct s_data
{
	mlx_t					*mlx;
	mlx_image_t				*img;
	t_obj					*objects;
	t_c						cam;
	t_a						amb;
	t_l						light;
}							t_data;

#endif
