/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:56:11 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 18:54:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		lem_in_count_channel(t_lem_in_data *data, int room_id)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < data->n_room)
	{
		if ((data->matrix)[room_id][i] == 1)
			count++;
		i++;
	}
	return (count);
}

static	void	lem_in_add_path_flow(t_lem_in_data *data, t_path *path)
{
	int	i;

	i = 0;
	while (i < data->n_room)
	{
		ft_memcpy((data->matrix_old)[i], (data->matrix)[i], data->n_room);
		i++;
	}
	i = 0;
	lem_in_add_flow(data, data->start, (path->path)[0]);
	while (i + 1 < path->steps)
	{
		lem_in_add_flow(data, (path->path)[i], (path->path)[i + 1]);
		i++;
	}
}

static	int		lem_in_draw_paths(t_lem_in_data *data, int max_paths)
{
	int		i;
	t_path	*shortest_path;
	int		old_is_better;

	old_is_better = 0;
	i = 0;
	while (i < max_paths && old_is_better == 0)
	{
		ft_printf("i = %d\n", i);
		shortest_path = lem_in_bfs_path(data);
		if (shortest_path == 0)
			max_paths = i;
		else
			lem_in_add_path_flow(data, shortest_path);
		i++;
		if (i > 1 && shortest_path != 0)
			old_is_better = lem_in_test_opti(data, i);
	}
	if (i == 0)
		return (-1);
	if (old_is_better == 1)
		lem_in_send_ants(data, i - 1, 1);
	else
		lem_in_send_ants(data, max_paths, 0);
	return (0);
}

int				lem_in_algo(t_lem_in_data *data)
{
	int		start_out;
	int		end_in;
	int		max_paths;

	start_out = lem_in_count_channel(data, data->start);
	end_in = lem_in_count_channel(data, data->end);
	max_paths = (start_out < end_in ? start_out : end_in);
	if (max_paths == 0 || lem_in_draw_paths(data, max_paths) == -1)
		return (-1);
	return (0);
}
