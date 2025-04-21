/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:49:27 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:44:50 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *str, int find, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char *)str)[i] == (unsigned char)find)
			return (&((unsigned char *)str)[i]);
		i++;
	}
	if (i == len)
		return (NULL);
	if (((unsigned char *)str)[i] == '\0' && (unsigned char)find == '\0')
	{
		return (&((unsigned char *)str)[i]);
	}
	return (NULL);
}
