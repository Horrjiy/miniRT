/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:10:16 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 16:17:14 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	ft_argvcheck(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (false);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	if (ft_strlen(argv[1]) < 4)
		return (false);
	if (ft_strncmp((argv[1]) + (ft_strlen(argv[1]) - 3), ".rt", 4) != 0)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (ft_argvcheck(argc, argv) == false)
		return (write(2, "Specify the path to a valid .rt file.\n", 38), 1);
	if (!ft_init(&data))
		return (ft_putstr_fd("Error", 2), 1);
	mlx_key_hook(data.mlx, keyfunc, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
