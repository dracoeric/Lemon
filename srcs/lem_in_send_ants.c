/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_send_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:13:51 by erli              #+#    #+#             */
/*   Updated: 2019/02/01 11:56:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
					int *id_ant)
{
	int j;
	int	end_of_line;

	j = paths[i].steps - 1;
	end_of_line = 0;
	if (paths[i].occupants[j] != 0)
		lem_in_print(paths[i].occupants[j], data->end);
	ft_memmove((paths[i].occupants) + 1, paths[i].occupants,
		paths[i].steps - 1);
	while (j >= 0)
	{
		if (i == 0 && j == 0)
			end_of_line = 1;
		if (paths[i].occupants[j] != 0)
			lem_in_print(data, paths[i].occupants[j], paths[i].path[j],
				end_of_line);
		j--;
		end_of_line = 0;
	}
	if (*id_ant >= (data->limits)[i])
	{
		paths[i].occupants[0] = *id_ant;
		lem_in_print(data, *id_ant, paths[i].path[0], 0);
		*id_ant += 1;
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
	data->buf_cursor = 0;
	id_ant = 1;
	n_steps;
	while (id_ants <= data->n_ant || lem_in_lines_not_empty(paths, max_paths))
	{
		i = max_paths - 1;
		while (i >= 0)
			lem_in_advance_line(data, paths, i++, &id_ant);
		n_steps++;
	}
	if (LI_OPT_STEPS(data->options))
	{
		ft_printf("\n====RESUME====\n%d ants moved from room ", data->n_ants);
		ft_printf("'%s' to room '%s' in %d steps\n",
			(data->anthill)[data->start]);
		ft_printf("'%s' in %d steps\n", (data->anthill)[data->end], n_steps);
	}
}

static	void	lem_in_get_limits(lem_in_data *data, int *steps,
					int max_paths)
{
	int a;
	int	i;

	a = 1;
	i = 1;
	(data->limits)[0] = 1;
	while (i < max_paths)
	{
		(data->limits)[i] = (data->limits)[i - 1]
			+ (steps[i] - steps[i - 1]) * a;
		i++;
		a++;
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
	lem_in_get_limits(data, steps, max_paths);
	lem_in_move_ants(data, paths, max_paths);
	i = 0;
	while (i < max_paths)
	{
		free(paths[i].path);
		free(paths[i].occupants);
		i++;
	}
}
