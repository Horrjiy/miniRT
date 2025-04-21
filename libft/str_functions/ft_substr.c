/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:45:16 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:44:05 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(str);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > (slen - start))
		len = slen - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while ((i < len))
	{
		substr[i] = str[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// Chatgpt test function (lol too lazy to make an own one)
// #include "libft.h"
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	char	*result;

// 	s = "Hello, World!";
// 	// Edge and special cases for testing
// 	printf("Testing ft_substr:\n");
// 	// Case 1: Normal case
// 	result = ft_substr(s, 0, 5); // "Hello"
// 	printf("ft_substr(\"%s\", 0, 5) = \"%s\"\n", s, result);
// 	free(result);
// 	// Case 2: Substring from the middle
// 	result = ft_substr(s, 7, 5); // "World"
// 	printf("ft_substr(\"%s\", 7, 5) = \"%s\"\n", s, result);
// 	free(result);
// 	// Case 3: Start beyond string length
// 	result = ft_substr(s, 20, 5); // NULL
// 	printf("ft_substr(\"%s\", 20, 5) = \"%s\"\n", s, result ? result : "NULL");
// 	free(result);
// 	// Case 4: Substring of length 0
// 	result = ft_substr(s, 5, 0); // Empty string
// 	printf("ft_substr(\"%s\", 5, 0) = \"%s\"\n", s, result ? result : "NULL");
// 	free(result);
// 	return (0);

// }
