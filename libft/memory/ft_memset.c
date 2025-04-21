/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:36:55 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:44:58 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*cs;
	size_t			i;

	i = 0;
	cs = (unsigned char *)str;
	while (i < len)
	{
		cs[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
