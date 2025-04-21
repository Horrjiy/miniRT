/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putunbr_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:06:07 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:01:45 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_puti(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}

static int	ft_iputunbr(unsigned int n, int *wrc)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		(*wrc)++;
		return (0);
	}
	if (n >= 10)
		if (ft_iputunbr((n / 10), wrc) == -1)
			return (-1);
	if (ft_puti((n % 10 + '0')) == -1)
		return (-1);
	(*wrc)++;
	return (0);
}

int	ufound(unsigned int f, int *wrc)
{
	if (ft_iputunbr(f, wrc) == -1)
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
