/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthexaddress_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:54 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:02:01 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	edgecase(int *wrc)
{
	if (write(1, "0", 1) == -1)
		return (-1);
	(*wrc)++;
	return (0);
}

static int	ft_putad(uintptr_t n)
{
	char	*str;

	str = "0123456789abcdef";
	if (write(1, &str[n], 1) == -1)
		return (-1);
	return (0);
}

static int	ft_putnbr_ad(uintptr_t n, int *wrc)
{
	if (n == 0)
		return (edgecase(wrc));
	if (n >= 16)
		ft_putnbr_ad((n / 16), wrc);
	(*wrc)++;
	if (ft_putad((n % 16)) == -1)
		return (-1);
	return (0);
}

int	pfound(void *f, int *wrc)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	*wrc += 2;
	if (!f)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		(*wrc)++;
		return (0);
	}
	if (ft_putnbr_ad((uintptr_t)f, wrc) == -1)
		return (-1);
	return (0);
}
