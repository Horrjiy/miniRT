/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:37:16 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:43:44 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	f;
	size_t	sublen;

	sublen = ft_strlen(substr);
	i = 0;
	if (substr[i] == '\0')
		return ((char *)str);
	if (len <= 0 || str[0] == '\0')
		return (NULL);
	while (i < len && str[i])
	{
		if (str[i] == substr[0])
		{
			f = 0;
			while (i + f < len && str[i + f] == substr[f] && str[i + f])
			{
				if (f + 1 == sublen)
					return ((char *)&str[i]);
				f++;
			}
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*kotz;
// 	char	*brocken;
// 	char	*s1;
// 	char	*s2;
// 	size_t	max;
// 	char	*mert;
// 	char	*mort;

// 	kotz = "Huber uock uel";
// 	brocken = "uock";
// 	printf("%s\n\n", ft_strnstr(kotz, brocken, 69));
// 	s1 = "oh no not the empty string !";
// 	s2 = "";
// 	max = 0;
// 	mert = strnstr(s1, s2, max);
// 	mort = ft_strnstr(s1, s2, max);
// 	if (mert == mort)
// 		printf("TEST_SUCCESS,\n%s\n%s\n\n", mert, mort);
// 	else
// 		printf("TEST_FAILED,\n%s\n%s\n\n", mert, mort);
// 	printf("S: %s\n", ft_strnstr(s2, "coucou", -1));
// 	printf("S: %s", strnstr(s2, "coucou", -1));
// 	return (0);
// }

// cc ft_memchr.c ft_strnstr.c ft_strlen.c -Wall -Wextra -Werror
