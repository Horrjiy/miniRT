/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:14:38 by tleister          #+#    #+#             */
/*   Updated: 2025/05/03 10:20:16 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

uint32_t	xorshift32(uint32_t *state)
{
	*state ^= *state << 21;
	*state ^= *state >> 28;
	*state ^= *state << 4;
	*state *= 1231238787231287;
	return (*state);
}

double	get_rand(void)
{
	static uint32_t	state = 0x61707865;

	return ((double)xorshift32(&state));
}
