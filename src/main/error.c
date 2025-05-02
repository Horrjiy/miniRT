/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:43:31 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/02 11:29:53 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	wr_err(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
}

void	ft_parserr(t_data *data, int exnum)
{
	free_data(data);
	if (exnum < 133)
		wr_err(strerror(exnum));
	else if (exnum == 201)
		wr_err("Couldn't read from file\n");
	else if (exnum == 202)
		wr_err("Invalid identifier\n");
	else if (exnum == 203)
		wr_err("Identifier C, L, A must appear exactly once\n");
	else if (exnum == 204)
		wr_err("Forbidden characters or format in an element\n");
	else if (exnum == 205)
		wr_err("Number out of range\n");
	else if (exnum == 206)
		wr_err("Directon vector can't have magnitute 0\n");
	else if (exnum == 207)
		wr_err("missing information\n");
	exit(exnum);
}
