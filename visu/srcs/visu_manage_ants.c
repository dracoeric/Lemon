/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_manage_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:12 by erli              #+#    #+#             */
/*   Updated: 2019/02/07 17:42:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int		visu_search_ant(t_ant **ant, int ant_id)
{
	if (*ant == 0)
		return (-1);
	while (*ant != 0)
	{
		if ((*ant)->id == ant_id)
			return (1);
		*ant = (*ant)->next;
	}
}

static	void	visu_manage_pheromon(t_visu_data *data, int ant_id,
					int origin, int dest)
{
	int	pheromon;

	if (VI_PHER_BLANK(data, origin, dest))
	{
		pheromon = (1 << (data->current_pheromon % 16));
		(data->current_pheromon)++;
		(data->matrix)[origin][dest] = (1 | pheromon << 1);
		(data->matrix)[dest][origin] = (1 | pheromon << 1);
		data->pioneers[ant_id] = pheromon;
	}
	else if (((data->matrix)[origin][dest] >> 1)
			 == data->pioneers[ant_id])
	{
		(data->matrix)[origin][dest] = 1;
		(data->matrix)[dest][origin] = 1;
		if (dest == data->start)
			data->pioneers[ant_id] = 0;
	}
}

static	int		visu_add_ant(t_visu_data *data, t_ant **ant, int ant_id,
					int room_id)
{
	t_ant	*elem;
	t_ant	bubble;
	int		origin;

	origin = (VI_PLAY_FORWARD(data->play_param) ? data->start : data->end);
	if (((data->matrix)[origin][room_id] & 1) != 1)
		return (ft_msg_int(2, "Illegal move, tunnel does not exist\n", -1));
	if (!(elem = (t_ant *)malloc(sizeof(t_ant))))
		return (ft_msg_int(2, "Failed malloc int add ant\n", -2));
	elem->id = ant_id;
	elem->pheromon = 0;
	elem->locations = room_id;
	elem->moved = 1;
	elem->next = NULL;
	if (data->ants == 0)
		data->ants = elem;
	else
	{
		bubble = data->ants;
		while (bubble->next != 0)
			bubble = bubble->next;
		bubble->next = elem;
	}
	return (visu_manage_pheromon(data, ant_id,
		(VI_PLAY_FORWARD(data->play_param) ? data->start : data->end),
		room_id));
	return (1);
}

static	int		visu_move_ants(t_visu_data *data, t_ant *ant, int room_id)
{



}

int				visu_manage_ants(t_visu_data *data, char *line, int ant_id,
					int len)
{
	char	room_name[len + 1];
	int		i;
	int		room_id;
	t_ant	ant;

	i = 0;
	ant = data->ants;
	while (line[i] != ' ' || line[i] != '\0')
	{
		name[i] = line[i];
		i++;
	}
	room_id = visu_rec_search(data->anthill, room_name, 0, data->n_room -1);
	if (room_id < 0)
		return (ft_msg_int(2, "Room does not exist.\n", -1));
	if (visu_search_ant(&ant, ant_id) < 0)
	{
		if (visu_add_ant(data, &ant, ant_id, room_id) < 0)
			return (-2);
		return (1);
	}
	else
		visu_move_ant(data, ant, room_id);
	return (1);
}
