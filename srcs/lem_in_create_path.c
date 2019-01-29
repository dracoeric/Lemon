/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_create_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:44:10 by erli              #+#    #+#             */
/*   Updated: 2019/01/29 18:18:35 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"
#include "libft.h"
#include <stdlib.h>

static	t_path	*lem_in_free_then_abort(t_path *path)
{
	free(path);
	return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
}

static	int		*lem_in_dup_path(int *dest, int *src, int steps)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		dest[i] = src[i];
		i++;
	}
}

t_path			*lem_in_create_path(t_lem_in_data *data, int room_id,
					int *n_path, t_path *dup)
{
	t_path	*elem;
	int		*tab;

	if (data == 0)
		return (ft_msg_ptr(2, "lem_in_data is null.\n", 0));
	if (!(elem = (t_path *)malloc(sizeof(t_path))))
		return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
	elem->path_id = *n_path;
	elem->steps = 1;
	elem->state = 0;
	elem->previous = NULL;
	elem->next = NULL;
	if (!(tab = (int *)malloc(sizeof(int) * data->n_ant)))
		return (lem_in_free_then_abort(elem));
	if (dup == 0)
	{
		elem->steps = dup->steps;
		lem_in_dup_path(elem->path, dup->path, dup->steps);
	}
	else
		(elem->path)[0] = data->start;
	*n_path += 1;
	(elem->path)[elem->steps - 1] = room_id;
	return (elem);
}
