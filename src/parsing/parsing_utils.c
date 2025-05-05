/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:57:14 by mpoplow           #+#    #+#             */
/*   Updated: 2025/05/05 16:44:38 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	split_line(t_data *data, char **line)
{
	int	i;

	i = 0;
	if (**line == '\0')
		return (ft_parserr(data, 207));
	(*line)++;
	if (ft_isalpha(**line))
		(*line)++;
	while (**line && ft_iswhtspc(**line))
		(*line)++;
	while ((*line)[i] && !ft_iswhtspc((*line)[i]))
		i++;
	data->str = malloc(i + 1);
	if (!data->str)
		return (ft_parserr(data, ENOMEM));
	ft_strlcpy(data->str, *line, i + 1);
	data->str[i] = '\0';
	while (**line && !ft_iswhtspc(**line))
		(*line)++;
}

void	ft_node_addback(t_obj **head, t_obj *node)
{
	t_obj	*temp;

	if (!node || !head)
		return ;
	if (!(*head))
	{
		*head = node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

t_obj	*ft_lastnode(t_obj *head)
{
	t_obj	*temp;

	if (!head)
		return (NULL);
	temp = head;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

t_obj	*init_object_node(int type, t_data *data)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		ft_parserr(data, ENOMEM);
	obj->type = type;
	obj->next = NULL;
	return (obj);
}
