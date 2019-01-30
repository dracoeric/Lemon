/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_trim_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:58:58 by erli              #+#    #+#             */
/*   Updated: 2019/01/30 09:18:00 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"
#include <stdlib.h>

static	void	lem_in_del_first(t_path **list)
{
	t_path *head;

	if (list == 0 || *list == 0 || (*list)->next == 0)
		return ;
	head = (*list)->next;
	head->previous - NULL;
	free((*list)->path);
	free(*list);
	*list = head;
}

static	void	lem_in_del_second(t_path **list)
{
	t_path *second;

	if (list == 0 || *list == 0 || (*list)->next == 0)
		return ;
	second = (*list)->next;
	if (second->next != 0)
		second->next->previous = *list;
	(*list)->next = second->next;
	free(second->path);
	free(second);
}

void			lem_in_trim_path(t_path **list)
{
	t_path	*next;

	if (list == 0 || *list == 0)
		return ;
	*list;
	while ((*list)->next != 0)
	{
		next = (*list)->next;
		if ((*list)->state != 1 || (next->steps < (*list)->steps
			&& next->state == 1))
			lem_in_del_first(list);
		else
			lem_in_del_second(list);
	}
}
