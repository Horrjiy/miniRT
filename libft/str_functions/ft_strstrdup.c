/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:10:03 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:43:49 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strstrdup(const char **src)
{
	char	**dest;
	size_t	i;

	i = 0;
	while (src[i] != NULL)
		i++;
	dest = malloc((i + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != NULL && src != NULL)
	{
		dest[i] = ft_strdup((const char *)src[i]);
		if (!dest[i])
		{
			while (i > 0)
				free(dest[--i]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
