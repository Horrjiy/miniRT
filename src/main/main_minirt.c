/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:10:16 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/29 15:29:03 by mpoplow          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	data;
	int fd;

	fd = ft_argvcheck(argc, argv);
	if (fd == -1)
		return (wr_err("Specify the path to a valid .rt file\n"), 1);
	ft_analyze(&data, fd);
	if (!ft_init(&data))
		return (ft_parserr(&data, ENOMEM), 12);
	ft_render(&data);
	mlx_key_hook(data.mlx, esc, &data);
	mlx_loop_hook(data.mlx, ft_keyfunc, &data);
	mlx_loop(data.mlx);
	free_data(&data);
}
