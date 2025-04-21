/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:06:07 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:01:58 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_put(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}

static int	edgecase(int n, int *wrc)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		(*wrc)++;
		return (0);
	}
	else if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		*wrc += 11;
		return (0);
	}
	else
		return (-1);
}

static int	ft_iputnbr(int n, int *wrc)
{
	if (n == 0 || n == -2147483648)
	{
		return (edgecase(n, wrc));
	}
	else if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		*wrc += 11;
		return (0);
	}
	if (n < 0)
	{
		n = -n;
		if (write(1, "-", 1) == -1)
			return (-1);
		(*wrc)++;
	}
	if (n >= 10)
		if (ft_iputnbr((n / 10), wrc) == -1)
			return (-1);
	if (ft_put((n % 10 + '0')) == -1)
		return (-1);
	return ((*wrc)++, 0);
}

int	difound(int f, int *wrc)
{
	if (ft_iputnbr(f, wrc) == -1)
		return (-1);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	ft_putnbr_fd(0, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-1, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-89, 1);
// 	printf("\n");
// 	ft_putnbr_fd(65, 1);
// 	printf("\n");
// 	ft_putnbr_fd(2147483647, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-2147483648, 1);
// 	printf("\n");
// }
