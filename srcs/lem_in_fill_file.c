/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_fill_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:39:55 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/30 18:56:29 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_parse.h"

void	lem_in_fill_file_cpynew_cpy(t_file **new, char *line, int len)
{
	newbuff = ft_strcpy(newbuff, line);
	(*new)->buff = newbuff;
	(*new)->buff[len] = '\n';
	(*new)->size = len + 1;
}

int		lem_in_fill_file_create_new(char *line, t_file *tmp, t_file **new, int len)
{
	char	*newbuff;

	if (!(*new = (t_file *)malloc(sizeof(t_file) * 1)))
		return (ft_msg_int(2, "Abort, failed malloc file", -1));
	if (!(newbuff = (char *)malloc(sizeof(char) * (B_SIZE + 1))))
	{
		free(new);
		return (ft_msg_int(2, "Abort, failed malloc buff_file", -1));
	}
	ft_bzero(newbuff, B_SIZE + 1);
	(*new)->next = NULL;
	if (tmp == NULL)
		lem_in_fill_file_cpynew_cpy(new, line, len, newbuff);
	else
	{
		tmp->buff = ft_strncpy(tmp->buff + tmp->size, line, B_SIZE - tmp->size);
		newbuff = ft_strcpy(newbuff, line + B_SIZE - tmp->size);
		(*new)->buff = newbuff;
		(*new)->size = len - (B_SIZE - tmp->size);
		tmp->size = tmp->size + B_SIZE - tmp->size;
		tmp->next = *new;
	}
	return (1);
}

int		lem_in_fill_file(char *line, t_file **file)
{
	t_file	*tmp;
	t_file	*new;
	int		len;

	tmp = *file;
	new = NULL;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	len = ft_strlen(line);
	if (tmp == NULL || (tmp->size + len + 1) > B_SIZE)
	{
		if (lem_in_fill_file_create_new(line, tmp, &new, len) < 0)
			return (-1);
		if (tmp == NULL)
			*file = new;
	}
	else
	{
		tmp->buff = ft_strcpy(tmp->buff + buff->size, line);
		tmp->buff[tmp->size + len] = '\n';
		tmp->size = len + 1;
	}
	return (1);
}
