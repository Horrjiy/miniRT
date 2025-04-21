/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:42:48 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:45:31 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	wordc;

	i = 0;
	wordc = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wordc++;
			while (s[i] != c && s[i])
				i++;
			continue ;
		}
		i++;
	}
	return (wordc);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**cut(char const *s, char **dest, char c, size_t d1)
{
	size_t	si;
	size_t	d2;

	si = 0;
	if (!dest)
		return (NULL);
	while (s[si])
	{
		dest[d1] = malloc(wordlen((s + si), c) + 1);
		if (!dest[d1])
		{
			while (d1 > 0)
				free(dest[--d1]);
			free(dest);
			return (NULL);
		}
		d2 = 0;
		while (s[si] && s[si] != c)
			dest[d1][d2++] = s[si++];
		dest[d1++][d2] = '\0';
		while (s[si] == c)
			si++;
	}
	dest[d1] = NULL;
	return (dest);
}

static char	**edge(const char *s)
{
	char	**dest;

	dest = malloc(sizeof(char *) * 2);
	if (!dest)
		return (NULL);
	dest[0] = malloc(ft_strlen(s) + 1);
	if (!dest[0])
	{
		free(dest);
		return (NULL);
	}
	ft_strlcpy(dest[0], s, ft_strlen(s) + 1);
	dest[1] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	wordcount;
	size_t	d1;

	if (s[0] == '\0')
		return (ft_calloc(sizeof(char *), 1));
	while (*s == c && *s != '\0')
		s++;
	if (c == '\0')
		return (edge(s));
	wordcount = wordcounter(s, c);
	if (wordcount == 0)
		return (ft_calloc(sizeof(char *), 1));
	d1 = 0;
	dest = cut(s, malloc(sizeof(char *) * (wordcount + 1)), c, d1);
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str;
// 	char	cha;
// 	char	**dst;
// 	int		i;

// 	i = 0;
// 	str = "hello!zzzzzzzz";
// 	cha = 'z';
// 	dst = ft_split(str, cha);
// 	while (dst[i])
// 	{
// 		printf("Final: %s\n", dst[i]);
// 		i++;
// 	}
// 	printf("Final: %s\n\n", dst[i]);
// 	system("leaks a.out");
// 	return (0);
// }
