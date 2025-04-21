/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:54:24 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:42:52 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)find)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == '\0' && (char)find == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	int		i;
// 	char	*s;
// 	s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	printf("str:'%s';\ni:'b'\nLocation:%s\n", s, ft_strchr(s, 'b'));
// 	printf("str:'%s';\ni:'b'\nLocation:%s\n\n", s, strchr(s, 'b'));
// 	printf("str:'%s';\ni:'!'\nLocation:%s\n", s, ft_strchr(s, '!'));
// 	printf("str:'%s';\ni:'!'\nLocation:%s\n\n", s, strchr(s, '!'));
// }
