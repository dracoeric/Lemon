/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_parse_get_rooms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:24:01 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/06 18:03:41 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

char	*visu_parse_get_rooms_ptr(t_file *file, int len, int *nbuff)
{
	t_file	*tmpfile;
	int		i;

	i = 0;
	tmpfile = file;
	while (tmpfile != NULL && tmpfile->next != NULL)
	{
		*nbuff = *nbuff + 1;
		tmpfile = tmpfile->next;
	}
	if (tmpfile->size < len + 1)
	{
		*nbuff = *nbuff - 1;
		tmpfile = file;
		while (i < *nbuff)
		{
			tmpfile = tmpfile->next;
			i++;
		}
	}
	return (tmpfile->buff + tmpfile->size - (len + 1));
}

int		visu_parse_get_rooms_place_room2(t_parse **tmp, t_parse **tmp2,\
		t_parse *new, int *tr)
{
	int min;

	min = new->size < (*tmp)->size ? new->size : (*tmp)->size;
	*tr = ft_strncmp(new->name, (*tmp)->name, min);
	if (*tr == 0 && new->size == (*tmp)->size)
	{
		free(new);
		return (ft_msg_int(2, "Abort, 2 rooms with same name", -1));
	}
	else if (*tr == 0 && new->size > (*tmp)->size)
	{
		*tr = *tr + 1;
	}
	if (*tr > 0)
	{
		*tmp2 = *tmp;
		*tmp = (*tmp)->next;
	}
	return (1);
}

int		visu_parse_get_rooms_place_room(t_parse **rooms, t_parse *new)
{
	t_parse	*tmp;
	t_parse	*tmp2;
	int		tr;

	tr = 1;
	tmp = *rooms;
	tmp2 = NULL;
	while (tmp != NULL && tr > 0)
	{
		if (visu_parse_get_rooms_place_room2(&tmp, &tmp2, new, &tr) == -1)
			return (-1);
	}
	if (tmp2 != NULL)
	{
		tmp2->next = new;
		new->next = tmp;
	}
	if (tmp2 == NULL)
	{
		new->next = tmp;
		*rooms = new;
	}
	return (1);
}

int		visu_parse_get_rooms_create(char *line, t_visu_data *data,\
		t_parse **rooms, t_file *file)
{
	t_parse	*new;
	int		len;
	int		nbuff;

	nbuff = 0;
	if (!(new = (t_parse *)malloc(sizeof(t_parse) * 1)))
		return (ft_msg_int(2, "Abort, failed malloc rparse", -1));
	len = ft_strlen(line);
	new->name = visu_parse_get_rooms_ptr(file, len, &nbuff);
	new->n_buff = nbuff;
	new->next = NULL;
	new->state = data->start == 1 ? 1 : 0;
	new->state = data->end == 1 ? 2 : new->state;
	data->start = data->start == 1 ? 2 : data->start;
	data->end = data->end == 1 ? 2 : data->end;
	data->n_room = data->n_room + 1;
	len = 1;
	while (line[len] != ' ')
		len++;
	new->size = len;
	if (*rooms == NULL)
		*rooms = new;
	else
		return (visu_parse_get_rooms_place_room(rooms, new));
	return (1);
}

int		visu_parse_get_rooms(char *l, t_visu_data *data, t_parse **rooms,\
		t_file *file)
{
	int	i;
	int	tr;

	tr = 1;
	i = 1;
	while (l[i] != '\0' && l[i] != ' ')
		i++;
	tr = l[i] != ' ' ? 0 : tr;
	while (tr == 1 && l[i] != '\0' && l[i] == ' ')
		i++;
	while (tr == 1 && l[i] != '\0' && l[i] != ' ' && ft_isdigit(l[i]) == 1)
		i++;
	tr = l[i] != ' ' ? 0 : tr;
	while (tr == 1 && l[i] != '\0' && l[i] == ' ')
		i++;
	while (tr == 1 && l[i] != '\0' && l[i] != ' ' && ft_isdigit(l[i]) == 1)
		i++;
	while (tr == 1 && l[i] != '\0' && l[i] == ' ')
		i++;
	if (tr == 1 && l[i] != '\0')
		tr = 0;
	if (tr == 1)
		tr = visu_parse_get_rooms_create(l, data, rooms, file);
	return (tr);
}
