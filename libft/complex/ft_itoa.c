/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:36:08 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:45:29 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	intsizecalc(int n)
{
	int	intsize;

	intsize = 0;
	while (n < -9 || n > 9)
	{
		n = n / 10;
		intsize++;
	}
	intsize++;
	return (intsize);
}

static char	*plusconvert(char *dest, int n, int intsize)
{
	dest = malloc(intsize + 1);
	if (!dest)
		return (NULL);
	dest[intsize] = '\0';
	while (intsize > 0)
	{
		intsize--;
		dest[intsize] = (n % 10) + '0';
		n = n / 10;
	}
	return (dest);
}

static char	*minusconvert(char *dest, int n, int intsize)
{
	intsize++;
	n = n * -1;
	dest = malloc(intsize + 1);
	if (!dest)
		return (NULL);
	dest[intsize] = '\0';
	while (intsize > 1)
	{
		intsize--;
		dest[intsize] = (n % 10) + '0';
		n = n / 10;
	}
	dest[0] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	int		intsize;
	char	*dest;

	dest = NULL;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	intsize = intsizecalc(n);
	if (n > 0)
		dest = plusconvert(dest, n, intsize);
	else
		dest = minusconvert(dest, n, intsize);
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("\nInt: %s", ft_itoa(0));
// 	printf("\nInt: %s", ft_itoa(2147483647));
// 	printf("\nInt: %s", ft_itoa(-2147483648));
// 	printf("\nInt: %s", ft_itoa(9));
// 	printf("\nInt: %s", ft_itoa(10));
// 	printf("\nInt: %s", ft_itoa(-9));
// 	printf("\nInt: %s", ft_itoa(-10));
// 	return (0);
// }