/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_bfs_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:19:10 by erli              #+#    #+#             */
/*   Updated: 2019/01/29 18:47:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"
#include "libft.h"
#include <stdlib.h>

static	void		lem_in_init_paths(t_lem_in_data *data, t_path **list,
						int *n_path)
{
	t_path	*elem;
	int		next;
	int		index;

	index = 0;
	next = lem_in_next_fork(data, data->start, &index);
	while (next != -1)
	{
		elem = lem_in_create_path(data, next, n_path, NULL);
		if (elem == 0)
		{
			lem_in_del_list(list);
			exit (ft_msg_int(2, "Abort, failed malloc in lem_in_init.\n", 0));
		}
		lem_in_path_add(list, elem);
		next = lem_in_next_fork(data, data->start, &index);
	}
}

t_path				*lem_in_bfs_path(s_lem_in_data *data)
{
	t_path	*list;
	t_path	*bubble;
	int		n_path;
	int		found;
	int		index;

	list = 0;
	n_path = 0;
	found = 0;
	lem_in_init_paths(data, list, data->start, &n_path);
	while (found == 0)
	{
		bubble = list;
		while (bubble != 0)
		{
/*	ajouter une premier noeud
 *	si fork, ajouter des elem dup a la list
 *	passer au path suivant etc
 */
			bubble = bubble->next;
		}
	}






}
