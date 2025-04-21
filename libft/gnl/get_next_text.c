/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:46:37 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:02:12 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_text_strjoin(char *endstr, char *stat)
{
	size_t	i;
	size_t	endlen;
	size_t	statlen;
	char	*dest;

	endlen = ft_strlen(endstr);
	statlen = ft_strlen(stat);
	dest = malloc(endlen + statlen + 1);
	if (!dest)
		return (free(endstr), NULL);
	i = -1;
	if (endstr)
		while (endstr[++i])
			dest[i] = endstr[i];
	i = 0;
	while (stat[i])
	{
		dest[endlen + i] = stat[i];
		i++;
	}
	dest[endlen + i] = '\0';
	free(endstr);
	return (dest);
}

char	*text_readerror(char *endstr)
{
	if (endstr)
		free(endstr);
	return (NULL);
}

char	*get_next_text(int fd)
{
	static char	statarr[BUFFER_SIZE + 1];
	char		*endstr;
	int			x;

	endstr = NULL;
	while (1)
	{
		if (statarr[0] != '\0')
		{
			endstr = ft_text_strjoin(endstr, statarr);
			if (!endstr)
				return (NULL);
			ft_bzero(statarr, BUFFER_SIZE + 1);
		}
		x = read(fd, statarr, BUFFER_SIZE);
		if (x > 0)
			statarr[x] = '\0';
		else if (x < 0)
			return (readerror(x, endstr));
		if (x == 0)
			return (endstr);
	}
	return (endstr);
}
