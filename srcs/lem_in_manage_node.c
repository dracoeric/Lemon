/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_manage_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 09:56:17 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 19:36:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		lem_in_do_fork(t_lem_in_data *data, t_path **bubble,
						int *n_path, int *index)
{
	int		next_id;
	int		room;
	t_path	*elem;

	room = ((*bubble)->path)[(*bubble)->steps - 2];
	next_id = lem_in_next_room(data, *bubble, room, index);
	while (next_id != -1)
	{
		elem = lem_in_create_path(data, next_id, n_path, *bubble);
		if (elem == 0)
		{
			ft_printf("iclai malloc\n");
			return (ft_msg_int(2, "Failed malloc.\n", -2));
		}
		lem_in_path_add(bubble, elem);
		if (next_id == data->end)
		{
			ft_printf("iclai fork end\n");
			return (1);
		}
		next_id = lem_in_next_room(data, *bubble, room, index);
	}
		ft_printf("iclai fork 0\n");
	return (0);
}

int				lem_in_manage_node(t_lem_in_data *data, t_path **bubble,
							int *n_path)
{
	int	index;
	int	next_id;
	int	room;

	index = 0;
	ft_printf("ici\n");
	if (((*bubble)) == 0)
		ft_printf("path null\n");
	ft_printf("path id %d\n", ((*bubble)->path)[0]);
	room = ((*bubble)->path)[(*bubble)->steps - 1];
	ft_printf("room = %d\n", room);
	next_id = lem_in_next_room(data, *bubble, room, &index);
	if (next_id != -1)
	{
		((*bubble)->path)[(*bubble)->steps] = next_id;
		(*bubble)->steps += 1;
		if (next_id == data->end)
		{
			ft_printf("iclai end\n");
			return (1);
		}
		return (lem_in_do_fork(data, bubble, n_path, &index));
	}
	else
		lem_in_rm_path(bubble, (*bubble)->path_id);
	ft_printf("iclai\n");
	return (0);
}
