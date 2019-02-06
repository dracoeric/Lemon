/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_create_anthill_matrix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:53:02 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/06 18:49:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int	visu_create_matrix(t_visu_data *data)
{
	int	i;

	if (!(data->matrix = (char **)malloc(sizeof(char *) * (data->n_room + 1))))
		return (ft_msg_int(2, "Abort, failed malloc matrix", -2));
	if (!(data->matrix_old = (char **)malloc(sizeof(char *)\
					* (data->n_room + 1))))
		return (ft_msg_int(2, "Abort, failed malloc matrix", -2));
	i = 0;
	while (i < data->n_room)
	{
		data->matrix[i] = ft_strnew(data->n_room);
		data->matrix_old[i] = ft_strnew(data->n_room);
		if (data->matrix[i] == NULL || data->matrix_old[i] == NULL)
			return (ft_msg_int(2, "Abort, failed malloc matrix", -2));
		i++;
	}
	data->matrix[data->n_room] = NULL;
	data->matrix_old[data->n_room] = NULL;
	return (0);
}

int			visu_create_anthill_matrix(t_visu_data *data, t_parse *rooms)
{
	int		i;
	t_parse	*tmp;

	i = 0;
	data->endroom = 1;
	if (data->start != 2 || data->end != 2)
		return (ft_msg_int(2, "Abort, no end or no start", -2));
	if (!(data->anthill = (t_room *)malloc(sizeof(t_room) * (data->n_room + 1))))
		return (ft_msg_int(2, "Abort, failed malloc create anthill", -2));
	tmp = rooms;
	i = 0;
	while (tmp != NULL)
	{
		if (!(data->anthill[i].name = ft_strsub(tmp->name, 0, tmp->size)))
			return (ft_msg_int(2, "Abort, failed malloc create anthill", -2));
		if (tmp->state != 0)
		{
			data->start = tmp->state == 1 ? i : data->start;
			data->end = tmp->state == 2 ? i : data->end;
		}
		i++;
		tmp = tmp->next;
	}
	data->anthill[data->n_room] = NULL;
	return (visu_create_matrix(data));
}
