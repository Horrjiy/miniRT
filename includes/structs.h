/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:05:19 by tleister          #+#    #+#             */
/*   Updated: 2025/04/25 12:25:49 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

// ~-~-~-~-~-~-~  coords and colors  ~-~-~-~-~-~-~ //

typedef struct s_coord
{
	double					x; // x coordinat
	double					y; // y coordinat
	double					z; // z coordinat
} t_coords, t_vect;

typedef struct s_rgb
{
	unsigned char			r; // red part
	unsigned char			g; // green part
	unsigned char			b; // blue part
}							t_rgbcolor;

// ~-~-~-~-~-~-~ scene elements ~-~-~-~-~-~-~ //

typedef struct s_ambient
{
	double					amb_light; // don't know. maybe the brigthness of the ambient ligth
	t_rgbcolor				rgb; // color
}							t_a;

typedef struct s_camera
{
	t_coords				pos; // position
	t_coords				vec; // vector to the direction the camera is looking
	int						fov; // field of view
}							t_c;

typedef struct s_light
{
	t_coords				pos; // position
	double					bright; // brightness I think
	t_rgbcolor				rgb; // color
}							t_l;

typedef struct s_sphere
{
	t_coords				pos; // position of the center
	double					dia; // diameter
	t_rgbcolor				rgb; // color
}							t_sp;

typedef struct s_plane
{
	t_coords				pos; // one point on the plain
	t_coords				nvec; // normaliced norm vector
	t_rgbcolor				rgb; // color
}							t_pl;

typedef struct s_cylinder
{
	t_coords				pos; // position of the center
	t_coords				vec; // direction vector of the line in the center
	double					dia; // diameter
	double					h; // height
	t_rgbcolor				rgb; // color 
}							t_cy;

// ~-~-~-~-~-~-~ management ~-~-~-~-~-~-~ //

typedef enum e_status
{
	sphere,
	plane,
	cylinder,
	shape_amount // not sure if this is needed will maybe get removed in the future
}							t_status;

typedef struct s_scene_objects
{
	t_status				type; // the object type
	struct s_scene_objects	*next; // pointer to another object or null
	union
	{
		t_sp				sphere;
		t_pl				plane;
		t_cy				cylinder;
	};
}							t_obj;

typedef struct s_hitpoint
{
	t_obj					*obj; // the closest hook thw ray is intersecting with
	t_rgbcolor				col; // the color of the object
	t_coords				point; // the intersection point
	double					dist; // the distance between cam and object
	double					t; // not sure if this is needed will maybe get removed in the future
}							t_hit;

//please do not put thing in there that are just needed at one point in the code
typedef struct s_data
{
	mlx_t					*mlx; // mlx window
	mlx_image_t				*img; // mlx image
	t_obj					*objects; // all the objects
	t_c						cam; // the camera
	t_a						amb; // the ambient ligth
	t_l						light; // a light source
	int						all_surroundings[3]; // Keeps track of witch of the mandatory things (camera, ambient, ligth) are set
	int						fd; // do we need this here ? it's for now just used at one point
	char					*temp; // why is a temp in our god struct? (and please be aware of double frees)
	char					**scene; 
}							t_data;

#endif
