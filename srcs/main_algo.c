/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:59:41 by erli              #+#    #+#             */
/*   Updated: 2019/01/28 18:11:37 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"

static	void	start(t_list_room *list_room, int count, int options)
{
	t_room		anthill[count];

	fill_anthill(anthill, count, options);
	lem_in_algo(anthill, count, options);

}

int				main(int argc, char **argv)
{
	t_list_room	*list_room;
	int			count;
	int			options;

	options = 0;
	manage_options(argc, argv, &options);
	count = 0;
	list_room = lem_in_parse(&count);
	start(list_room, count, options);
	return (0);
}
