/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:10:16 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 14:48:15 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	main(int argc, char *argv[])
{
	t_coords shrek;
	shrek.x = 5;
	shrek.y = -3;
	shrek.z = 2.5;
	ft_normalize_vector(&shrek);
	if (ft_argvcheck(argc, argv) == false)
		return (write(2, "Specify the path to a valid .rt file.\n", 38), 1);
}
