/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_send_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:13:51 by erli              #+#    #+#             */
/*   Updated: 2019/01/31 16:37:06 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"
#include "libft.h"

static	int		lem_in_lines_not_empty(t_path *paths, int max_paths)
{
	int i;
	int j;

	i = 0;
	while (i < max_paths)
	{
		j = 0;
		while (j < paths[i].steps)
		{
			if (paths[i].occupants[j] != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static	void	lem_in_advance_line(t_lem_in_data *data, t_path *paths, int i,
					int max_paths)
{
	int j;

	j = paths[i].steps - 1;
	if (paths[i].occupants[j] != 0)
		lem_in_print(paths[i].occupants[j], data->end);
	ft_memmove((paths[i].occupants) + 1, paths[i].occupants,
		paths[i].steps - 1);
	while (j >= 0)
	{
		if (paths[i].occupants[j] != 0)
			lem_in_print(data, paths[i].occupants[j], paths[i].path[j]);
		j--;
	}
}

static	void	lem_in_move_ants(t_lem_in_data *data, t_path *paths,
					int max_paths)
{
	int		id_ant;
	int		i;
	char	buf[B_SIZE + 1];
	int		n_steps;

	ft_bzero(buf, B_SIZE + 1);
	data->buf = buf;
	id_ant = 1;
	n_steps;
	while (id_ants <= data->n_ant || lem_in_lines_not_empty(paths, max_paths))
	{
		i = max_paths - 1;
		while (i >= 0)
			lem_in_advance_line(data, paths, i++, &id_ant);
		lem_in_add_newline(data);
		n_steps++;
	}
	if (LI_OPT_STEPS(data->options))
	{
		ft_printf("\n====RESUME====\n%d ants moved from room ", data->n_ants);
		ft_printf("'%s' to room '%s' in %d steps\n",
			data->anthill[data->start]);
		ft_printf("'%s' in %d steps\n", data->anthill[data->end], n_steps);
	}
}

void			lem_in_send_ants(t_lem_in_data *data, int max_paths, int mode)
{
	char	**matrix;
	int		steps[max_paths];
	int		limits[max_paths];
	t_path	paths[max_paths];
	int		i;

	i = 0;
	matrix = (mode == 1 ? data->matrix_old : data->matrix);
	lem_in_get_steps(data, matrix, steps, max_paths);
	while (i < max_paths)
	{
		paths[i].steps = steps[i];
		i++;
	}
	data->limits = limits;
	lem_in_magic_paths(data, matrix, paths, max_paths);
	lem_in_get_limits(data, matrix, steps, max_paths);
	lem_in_move_ants(data, paths, max_paths);
}
