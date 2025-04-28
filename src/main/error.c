/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:43:31 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/28 10:28:09 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void wr_err(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
}

void ft_parserr(t_data *data, int exnum)
{
	free_data(data);
	if(exnum < 133)
		wr_err(strerror(exnum));
	else if(exnum == 201)
		wr_err("Couldn't read from file");
	else if(exnum == 202)
		wr_err("Invalid identifier");
	else if(exnum == 203)
		wr_err("Identifier C, L, A must appear exactly once");
	exit(exnum);
}
