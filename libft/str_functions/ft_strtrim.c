/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:42:28 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/02 15:44:00 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count(char const *s1, char const *set, int i)
{
	int	c;

	c = 0;
	while (set[c])
	{
		if (s1[i] == set[c])
			return (1);
		c++;
	}
	return (0);
}

static int	ltrimcount(char const *s1, char const *set)
{
	int	i;
	int	ltrimc;

	ltrimc = 0;
	i = 0;
	while (s1[i])
	{
		if (count(s1, set, i) == 1)
			ltrimc++;
		else
			break ;
		i++;
	}
	return (ltrimc);
}

static int	rtrimcount(char const *s1, char const *set)
{
	int	i;
	int	rtrimc;

	rtrimc = 0;
	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if (count(s1, set, i) == 1)
			rtrimc++;
		else
			break ;
		i--;
	}
	return (rtrimc);
}

static char	*trim(const char *s1, int ltrimc, int rtrimc)
{
	char	*temp;
	int		i;
	int		trim;

	i = 0;
	trim = ft_strlen(s1) - ltrimc - rtrimc;
	temp = malloc(trim + 1);
	if (!temp)
		return (NULL);
	while (i < trim)
	{
		temp[i] = s1[ltrimc + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	ltrimc;
	int	rtrimc;

	if (s1[0] == '\0')
		return (ft_strdup(""));
	else if (set[0] == '\0')
		return (ft_strdup(s1));
	ltrimc = ltrimcount(s1, set);
	rtrimc = rtrimcount(s1, set);
	if ((int)ft_strlen(s1) <= (ltrimc + rtrimc))
		return (ft_strdup(""));
	return (trim(s1, ltrimc, rtrimc));
}
