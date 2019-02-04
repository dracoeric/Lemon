/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:53:27 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 14:41:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_print_path(t_path *path)
{
	ft_printf("=======printing path==========\n");
	if (path == 0)
	{
		ft_printf("list is empty\n");
		return ;
	}
	while (path != 0)
	{
		ft_printf("path %d\nsteps = %d\n, path = %td\n", path->path_id,
			path->steps, path->path, path->steps);
		path = path->next;
	}
}
