/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_rm_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:38:32 by erli              #+#    #+#             */
/*   Updated: 2019/01/29 16:50:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"
#include <stdlib.h>

void		lem_in_rm_path(t_path **list, int path_id)
{
	t_path *bubble;

	if (list == 0 || *list == 0)
		return ;
	bubble = *list;
	while (bubble->path_id != path_id && bubble != 0)
		bubble = bubble->next;
	if (bubble != 0)
	{
		if (bubble->previous != 0)
			bubble->previous->next = bubble->next;
		if (bubble->next != 0)
			bubble->next->previous = bubble->previous;
		if (bubble == *list)
			*list = (*list)->next;
		free(bubble->path);
		free(bubble);
	}
}
