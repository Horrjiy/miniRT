/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:28:07 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 17:01:38 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	percentage(const char *str, va_list arglist, int i, int *wrc)
{
	int	error;

	if (str[i] == '\0')
		return (-1);
	else if (str[i] == 'c')
		error = cfound(va_arg(arglist, int), wrc);
	else if (str[i] == 's')
		error = sfound(va_arg(arglist, char *), wrc);
	else if (str[i] == 'd' || str[i] == 'i')
		error = difound(va_arg(arglist, int), wrc);
	else if (str[i] == 'u')
		error = ufound(va_arg(arglist, unsigned int), wrc);
	else if (str[i] == 'x')
		error = lowxfound(va_arg(arglist, unsigned int), wrc);
	else if (str[i] == 'X')
		error = capxfound(va_arg(arglist, unsigned int), wrc);
	else if (str[i] == 'p')
		error = pfound(va_arg(arglist, void *), wrc);
	else if (str[i] == '%')
		error = percfound(wrc);
	else
		return (-1);
	if (error == -1)
		return (-1);
	return (*wrc);
}

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	int		i;
	int		wrc;

	va_start(arglist, str);
	i = 0;
	wrc = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			wrc = percentage(str, arglist, i + 1, &wrc);
			if (wrc == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write(1, &str[i], 1) == -1)
				return (-1);
			wrc++;
		}
		i++;
	}
	return (va_end(arglist), wrc);
}
