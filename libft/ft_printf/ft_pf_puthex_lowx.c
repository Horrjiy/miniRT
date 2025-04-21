/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthex_lowx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:54 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:02:03 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_puthex(unsigned int cast)
{
	char	*str;

	str = "0123456789abcdef";
	if (write(1, &str[cast], 1) == -1)
		return (-1);
	return (0);
}

static int	ft_putnbr_hex(unsigned int n, int *wrc)
{
	unsigned long	cast;

	cast = (unsigned long)n;
	if (cast == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		(*wrc)++;
		return (0);
	}
	if (cast >= 16)
	{
		if (ft_putnbr_hex((cast / 16), wrc) == -1)
			return (-1);
	}
	(*wrc)++;
	if (ft_puthex((cast % 16)) == -1)
		return (-1);
	return (0);
}

int	lowxfound(int f, int *wrc)
{
	if (ft_putnbr_hex(f, wrc) == -1)
		return (-1);
	return (0);
}
