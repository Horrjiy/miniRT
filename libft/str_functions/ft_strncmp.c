/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:57:45 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:43:41 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] && (unsigned char)s2[i] && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (((unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0')
		|| i == n)
		return (0);
	if ((unsigned char)s1[i] == '\0' && (unsigned char)s2[i] != '\0')
		return (0 - (unsigned char)s2[i]);
	else
		return ((unsigned char)s1[i]);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// char *s1 = "Salut";
// char *s2 = "Salute";
// int was;
// printf("s1: '%s';   s2: '%s' \n", s1, s2);
// was = ft_strncmp(s1, s2, 5);
// printf("Was: %d\n", was);
// was = ft_strncmp(s1, s2, 2);
// printf("Was: %d\n", was);
// was = ft_strncmp(s1, s2, 9);
// printf("Was: %d\n\n", was);
// was = strncmp(s1, s2, 5);
// printf("Was: %d\n", was);
// was = strncmp(s1, s2, 2);
// printf("Was: %d\n", was);
// was = strncmp(s1, s2, 9);
// printf("Was: %d\n", was);

// 	char *big = "abcdef";
// 	char *little = "abcdefghijklmnop";
// 	size_t size = 6;
// 	int i1 = ((strncmp(big, little, size) > 0) ? 1 : ((strncmp(big, little,
// size) < 0) ? -1 : 0));
// 	int i2 = ((ft_strncmp(big, little, size) > 0) ? 1 : ((ft_strncmp(big,
// little, size) < 0) ? -1 : 0));

// 	if (i1 == i2)
// 	{
// 		printf("\nTEST_SUCCESS: strncmp %d; ft_strncmp %d;", i1, i2);
// 		return(0);
// 	}
// 	printf("\nTEST_FAILED: strncmp %d; ft_strncmp %d;", i1, i2);
// 	return(0);
// }