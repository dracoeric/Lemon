/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:37:55 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/01 18:12:39 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	lem_in_free_file(t_file **file)
{
	t_file *tmp;

	tmp = *file;
	if (file == NULL || *file == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free((*file)->buff);
		(*file)->buff = NULL;
		free(*file);
		*file = NULL;
		*file = tmp;
	}
}

void	lem_in_free_tabchar(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	if (*tab == NULL)
	{
		free(tab);
		return ;
	}
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	lem_in_free_data(t_lem_in_data **data)
{
	if (data != NULL)
	{
		if ((*data)->file != NULL)
			lem_in_free_file(&(*data)->file);
		lem_in_free_tabchar((*data)->anthill);
		lem_in_free_tabchar((*data)->matrix);
		lem_in_free_tabchar((*data)->matrix_old);
		if ((*data)->limits != NULL)
			free((*data)->limits);
		if ((*data)->buf != NULL)
			free((*data)->buf);
		free(*data);
		*data = NULL;
	}
}

void	lem_in_free_rooms(t_parse **rooms)
{
	t_parse	*tmp;

	tmp = *rooms;
	if (rooms == NULL || *rooms == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*rooms);
		*rooms = NULL;
		*rooms = tmp;
	}
	return ;
}
