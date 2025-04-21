/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:46:37 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:02:10 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*readerror(int x, char *endstr)
{
	if (x == 0)
		return (endstr);
	else
	{
		if (endstr)
			free(endstr);
		return (NULL);
	}
}

int	setstat(int fd, char *statarr)
{
	int	x;

	x = read(fd, statarr, BUFFER_SIZE);
	if (x > 0)
		statarr[x] = '\0';
	return (x);
}

int	nlcheck(char *str, char *statarr)
{
	int	i;

	i = 0;
	move(statarr);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	statarr[BUFFER_SIZE + 1];
	char		*endstr;
	int			x;

	endstr = NULL;
	while (1)
	{
		if (statarr[0] != '\0')
		{
			endstr = buff_strjoin(endstr, statarr);
			if (!endstr)
				return (NULL);
			if (nlcheck(endstr, statarr) == 1)
				break ;
		}
		x = setstat(fd, statarr);
		if (x <= 0)
			return (readerror(x, endstr));
		endstr = buff_strjoin(endstr, statarr);
		if (!endstr)
			return (NULL);
		if (nlcheck(endstr, statarr) == 1)
			break ;
	}
	return (endstr);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*rudolf;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	while (i < 17)
// 	{
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

// x = ft_strlen(endstr);
