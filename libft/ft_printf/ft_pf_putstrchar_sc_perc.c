/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstrchar_sc_perc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:01:32 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:01:49 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	cfound(char f, int *wrc)
{
	if (write(1, &f, 1) == -1)
		return (-1);
	(*wrc)++;
	return (0);
}

int	sfound(char *f, int *wrc)
{
	size_t	temp;

	if (f == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		(*wrc) += 6;
		return (0);
	}
	temp = 0;
	while (f[temp])
	{
		if (write(1, &f[temp], 1) == -1)
			return (-1);
		temp++;
		(*wrc)++;
	}
	return (0);
}

int	percfound(int *wrc)
{
	if (write(1, "%%", 1) == -1)
		return (-1);
	(*wrc)++;
	return (0);
}
