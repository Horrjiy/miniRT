/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:57:41 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 10:50:23 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// ~-~-~-~-~-~-~  Includes  ~-~-~-~-~-~-~ //

# include <stdbool.h>
# include <unistd.h>

// ~-~-~-~-~-~-~  Definitions and structs; idk, bro Tammo lass dir was besseres einfallen ey  ~-~-~-~-~-~-~ //

typedef struct s_data
{
	int	test;
}		t_data;

// ~-~-~-~-~-~-~  Functions  ~-~-~-~-~-~-~ //

bool ft_argvcheck(int argc, char **argv);

#endif