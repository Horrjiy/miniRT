/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:44:49 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:43:26 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	if (destsize == 0 || (destsize <= dlen))
		return (destsize + slen);
	while (i < ((destsize - dlen) - 1) && src[i])
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
