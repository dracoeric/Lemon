/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_manage_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 09:56:17 by erli              #+#    #+#             */
/*   Updated: 2019/01/30 17:50:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"

static	int		lem_in_do_fork(t_lem_in_data *data, t_path **bubble,
						int *n_path, int index)
{
	int		next_id;
	int		room;
	t_path	*elem;

	room = ((*bubble)->path)[(*bubble)->steps - 2];
	next_id = lem_in_next_room(data, room, &index);
	while (next_id != -1)
	{
		elem = lem_in_create(data, next_id, n_path, *bubble);
		if (elem == 0)
			return (-2);
		lem_in_path_add(bubble, elem);
		next_id = lem_in_next_room(data, room, &index);
	}
}

int				lem_in_manage_node(t_lem_in_data *data, t_path **bubble,
							int *n_path)
{
	int	index;
	int	next_id;
	int	room;

	index = 0;
	room = ((*bubble)->path)[(*bubble)->steps - 1];
	next_id = lem_in_next_room(data, room, &index);
	if (next_id != -1)
	{
		((*bubble)->path)[(*bubble)->steps] = next_id;
		(*bubble)->steps += 1;
		if (next_id == data->end)
			return (1);
		return (lem_in_do_fork(data, bubble, n_path, *index));
	}
	else
		lem_in_rm_path(bubble, room);
	return (0);
}
