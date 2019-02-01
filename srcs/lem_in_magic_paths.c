/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_magic_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:22:28 by erli              #+#    #+#             */
/*   Updated: 2019/02/01 11:54:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	lem_in_init_paths(t_path *paths, int max_paths)
{
	int i;

	i = 0;
	while (i < max_paths)
	{
		if (!(path[i].occupants = (int *)malloc(sizeof(int) * max_paths)))
			exit(ft_msg_int(2, "Abort, failed malloc.\n", 0));
		if (!(path[i].paths = (int *)malloc(sizeof(int) * max_paths)))
			exit(ft_msg_int(2, "Abort, failed malloc.\n", 0));
		i++;
	}
}

static	void	lem_in_fill_paths(t_lem_in_data *data, char **matrix,
					t_path *paths, int max_paths)
{
	int i;
	int	j;
	int	start_room;
	int	room;
	int	next;

	i = 0;
	start_room = 0;
	while (i < max_paths)
	{
		while (!((matrix[data->start][start_room] & 7) == 7))
			start_room++;
		paths[i].path[0] = start_room;
		j = 1;
		while (j < paths[i].steps)
		{
			room = 0;
			while (!((matrix[paths[i].path[j - 1]][room] & 7) == 7))
				room++;
			paths[i].path[j] = room;
			j++;
		}
		i++;
	}
}

void			lem_in_magic_paths(t_lem_in_data *data, char **matrix,
					t_path *paths, int max_paths)
{
	int i;
	int j;

	lem_in_init_paths(paths, max_paths);
	lem_in_fill_paths(data, matrix, paths, max_paths);
	i = max_paths;
	while (i > 0)
	{
		j = 0;
		while (j + 1 < i)
		{
			if (paths[i].steps[j + 1] < paths[i].steps[j])
			{
				ft_swap_int((paths[i].steps) + j, (paths[i].steps) + j + 1);
				ft_swap_int((paths[i].path) + j, (paths[i].path) + j + 1);
			}
			j++;
		}
		i--;
	}
}
