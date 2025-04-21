/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:35:53 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:02:08 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	nlstrlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

char	*buff_strjoin(char *endstr, char *stat)
{
	int		i;
	size_t	endlen;
	size_t	statlen;
	char	*dest;

	endlen = ft_strlen(endstr);
	statlen = nlstrlen(stat);
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
		if (stat[i++] == '\n')
			break ;
	}
	dest[endlen + i] = '\0';
	free(endstr);
	return (dest);
}

int	move(char statarr[])
{
	size_t	i;

	while (statarr[0] != '\n' && statarr[0] != '\0')
	{
		i = 0;
		while (statarr[i + 1] != '\0')
		{
			statarr[i] = statarr[i + 1];
			i++;
		}
		statarr[i] = '\0';
	}
	i = 0;
	if (statarr[0] == '\n')
	{
		while (statarr[i + 1] != '\0')
		{
			statarr[i] = statarr[i + 1];
			i++;
		}
		statarr[i] = '\0';
		return (1);
	}
	return (0);
}
