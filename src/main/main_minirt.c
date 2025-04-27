/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:10:16 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/27 12:50:54 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_argvcheck(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (-1);
	if (ft_strlen(argv[1]) < 4)
		return (-1);
	if (ft_strncmp((argv[1]) + (ft_strlen(argv[1]) - 3), ".rt", 4) != 0)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	return (fd);
}

t_obj	*setup_obj(void)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	obj->next = NULL;
	obj->sphere.dia = 10;
	obj->sphere.pos.x = 15;
	obj->sphere.pos.y = 0;
	obj->sphere.pos.z = 0;
	obj->sphere.rgb.r = 255;
	obj->sphere.rgb.g = 0;
	obj->sphere.rgb.b = 0;
	obj->type = sphere;
	return (obj);
}

t_l	setup_ligth(void)
{
	t_l	ligth;

	ligth.pos.x = 15;
	ligth.pos.y = 5;
	ligth.pos.z = -15;
	
	ligth.bright = 0.9;
	ligth.rgb.r = 255;
	ligth.rgb.g = 255;
	ligth.rgb.b = 255;
	return (ligth);
}

t_c	setup_cam(void)
{
	t_c	cam;

	cam.pos.x = 0;
	cam.pos.y = 0;
	cam.pos.z = 0;
	cam.vec.x = 1;
	cam.vec.y = 0;
	cam.vec.z = 0;
	cam.fov = 1;
	return (cam);
}

t_a setup_amp(void)
{
	t_a amp;
	amp.amb_light = 0.6;
	amp.rgb.r = 255;
	amp.rgb.g = 255;
	amp.rgb.b = 255;
	return amp;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	// data.fd = ft_argvcheck(argc, argv);
	// if (data.fd == -1)
	// 	return (wr_err("Specify the path to a valid .rt file.\n"), 1);
	if (!ft_init(&data))
		return (ft_putstr_fd("Error", 2), 1);
	data.objects = setup_obj();
	data.cam = setup_cam();
	data.light = setup_ligth();
	data.amb = setup_amp();
	ft_render(&data);
	mlx_key_hook(data.mlx, esc, &data);
	mlx_loop_hook(data.mlx, ft_keyfunc, &data);
	mlx_resize_hook(data.mlx, ft_resizefunc, &data);
	mlx_loop(data.mlx);
	free_data(&data);
}
