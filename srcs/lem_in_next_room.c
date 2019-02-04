/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_next_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:28:32 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 14:36:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		lem_in_is_previous(t_lem_in_data *data, t_path *path,
						int room_candidat)
{
	if (path == 0)
		return (0);
	if (path->steps == 1 && room_candidat == data->start)
		return (1);
	if (path->steps < 2)
		return (0);
	if ((path->path)[path->steps - 2] == room_candidat)
		return (1);
	else
		return (0);
}

int				lem_in_next_room(t_lem_in_data *data, t_path *path, int n_room,
						int *index)
{
	if (*index >= data->n_room)
		return (-1);
	else
	{
		while (*index < data->n_room)
		{
			if (!(lem_in_is_previous(data, path, *index))
				&& LI_CONNECTED(data, n_room, *index)
				&& !(LI_FLOW_CAPPED(data, n_room, *index)))
			{
				*index += 1;
				return (*index - 1);
			}
			*index += 1;
		}
		return (-1);
	}
}
