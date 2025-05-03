/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:05:19 by tleister          #+#    #+#             */
/*   Updated: 2025/05/03 10:19:00 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

// ~-~-~-~-~-~-~  coords and colors  ~-~-~-~-~-~-~ //

typedef struct s_coord
{
	double x; // x coordinate
	double y; // y coordinate
	double z; // z coordinate
} t_coords, t_vect;

typedef struct s_rgbcolor
{
	unsigned char r; // red part
	unsigned char g; // green part
	unsigned char b; // blue part
}				t_rgb;

typedef struct s_color_brigthness
{
	double r; // red part
	double g; // green part
	double b; // blue part
}				t_b_rgb;

// ~-~-~-~-~-~-~ scene elements ~-~-~-~-~-~-~ //

typedef struct s_ambient
{
	double amb_light; // ambient lighting ratio
	t_rgb rgb;        // color
}				t_a;

typedef struct s_camera
{
	t_vect right; // vector that faces right relative to screen
	t_vect up;    // vector that faces up relative to screen
	t_coords pos; // position of the view point
	t_coords vec; // normalized vector to the direction the camera is looking
	double fov;   // Horizontal field of view
}				t_c;

typedef struct s_light
{
	t_coords pos;  // position of the light point
	double bright; // brightness
	t_rgb rgb;     // color (unused in mandatory part)
}				t_l;

typedef struct s_sphere
{
	t_coords pos; // position of the center
	double dia;   // diameter
	t_rgb rgb;    // color
}				t_sp;

typedef struct s_plane
{
	t_coords pos;  // one point on the plain
	t_coords nvec; // normalized norm vector
	t_rgb rgb;     // color
}				t_pl;

typedef struct s_cylinder
{
	t_coords pos; // position of the center
	t_coords vec; // direction vector of the line in the center
	double dia;   // diameter
	double h;     // height
	t_rgb rgb;    // color
}				t_cy;

typedef struct s_cone
{
	t_coords pos; // position of the top
	t_coords vec; // direction vector of the line in the center
	double dia;   // diameter at the widest point
	double h;     // height
	t_rgb rgb;    // color
}				t_co;

// ~-~-~-~-~-~-~ management ~-~-~-~-~-~-~ //

typedef enum e_status
{
	sphere,
	plane,
	cylinder,
	cone,
	shape_amount
	// not sure if this is needed will maybe get removed in the future
}				t_status;

typedef struct s_scene_objects
{
	t_status type;                // the object type
	struct s_scene_objects *next; // pointer to another object or null
	union
	{
		t_sp	sphere;
		t_pl	plane;
		t_cy	cylinder;
		t_co	cone;
	};
}				t_obj;

typedef struct s_hitpoint
{
	t_obj *obj;     // the closest shape the ray is intersecting with
	t_vect normal;  // normal vector of the obj
	t_b_rgb col;    // the color of the object
	t_coords point; // the intersection point
	double dist;    // the distance between cam and object
}				t_hit;

// please do not put thing in there that are just needed at one point in the code
typedef struct s_data
{
	mlx_t *mlx;        // mlx window
	mlx_image_t *img;  // mlx image
	t_obj *objects;    // all the objects
	t_c cam;           // the camera
	t_a amb;           // the ambient light
	t_l light;         // a light source
	int all_surrnd[3]; // tracks camera ambient and light
	char *str;         // A string; still overcomplicated
	char		**scene;
	double width;  // projection plane height
	double height; // projection plane width
}				t_data;

#endif
