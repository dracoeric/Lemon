/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_send_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:13:51 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 17:45:26 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

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
	ft_memmove((paths[i].occupants) + 1, paths[i].occupants,
			   sizeof(int) * (paths[i].steps - 1));
	paths[i].occupants[0] = 0;
	end_of_line = 0;
	while (j > 0)
	{
		if (paths[i].occupants[j] == data->n_ant)
			end_of_line = 1;
		if (paths[i].occupants[j] != 0)
			lem_in_print(data, paths[i].occupants[j], paths[i].path[j],
				end_of_line);
		end_of_line = 0;
		j--;
	}
	if ((data->n_ant + 1 - *id_ant) >= (data->limits)[i] && *id_ant <= data->n_ant)
	{
		paths[i].occupants[0] = *id_ant;
		if (i == 0)
			end_of_line = 1;
		lem_in_print(data, *id_ant, paths[i].path[0], end_of_line);
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
	n_steps = 0;
	while (id_ant <= data->n_ant || lem_in_lines_not_empty(paths, max_paths))
	{
		i = max_paths - 1;
		while (i >= 0)
			lem_in_advance_line(data, paths, i--, &id_ant);
		n_steps++;
	}
//	if (LI_OPT_STEPS(data->options))
		lem_in_print_total_step(data, n_steps - 1);
}

static	void	lem_in_get_limits(t_lem_in_data *data, int *steps,
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

	ft_printf("max_paths = %d\n", max_paths);
	data->fd = 1;
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
	ft_merge_sort_tab(steps, steps, max_paths);
	lem_in_get_limits(data, steps, max_paths);
	
	i = 0;
	ft_printf("\n==========opti paths========\n");
	while (i < max_paths)
	{
		ft_printf("path %d = %td\n", i, paths[i].path, paths[i].steps);
		i++;
	}
	ft_printf("limits = %td\n", limits, max_paths);


	lem_in_move_ants(data, paths, max_paths);
	(data->buf)[data->buf_cursor - 1] = '\n';
	write(data->fd, data->buf, data->buf_cursor);
	i = 0;
	while (i < max_paths)
	{
		free(paths[i].path);
		free(paths[i].occupants);
		i++;
	}
}
