/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:13:12 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/01 13:41:38 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"


int				lem_in_parse_get_ants(char *line, t_lem_in_data *data)
{
	int	i;

	i = 1;
	if (line[0] != '+' && ft_isdigit(line[0]) == 0)
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	while (line[i] != '\0' && ft_isdigit(line[i]) == 1)
		i++;
	if (line[i] == '\0')
		lem_in_atoi(line, &(data->n_ant));
	else
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	if (data->n_ant == 0)
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	return (1);
}

int				lem_in_parse_get_other(char *line, t_lem_in_data *data, t_parse **rooms, t_file *file)
{
	int	tr;
	int	i;
	t_parse *tmp;

	tr = 0;
	if (data->endroom == 0)
		tr = lem_in_parse_get_rooms(line, data, rooms, file);
	if (tr == 0 && data->endroom == 0)
	{
		data->endroom = 1;
		//proteger les 2 malloc
		data->anthill = (char **)malloc(sizeof(char *) * (data->n_room + 1));
		tmp = *rooms;
		i = 0;
		while (tmp != NULL)
		{
			data->anthill[i] = ft_strsub(tmp->name, 0, tmp->size);
			i++;
			tmp = tmp->next;
		}
		data->matrix = (char **)malloc(sizeof(char *) * (data->n_room + 1));
		data->matrix_old = (char **)malloc(sizeof(char *) * (data->n_room + 1));
		i = 0;
		while (i < data->n_room)
		{
			//proteger aussi
			data->matrix[i] = ft_strnew(data->n_room);
			data->matrix_old[i] = ft_strnew(data->n_room);
			i++;
		}
		data->matrix[data->n_room] = NULL;
		data->matrix_old[data->n_room] = NULL;
	}
	if (tr == 0 && data->endroom == 1)
		tr = lem_in_parse_get_links(line, data);
	if (tr == 0)
		return (ft_msg_int(2, "Abort, not a pipe, not a room", -1));
	return (tr);
}

int				lem_in_parse_line(char *line, t_lem_in_data *data, t_file **file, t_parse **rooms)
{
	int	tr;

	tr = 1;
	if (lem_in_fill_file(line, file) < 0)
		return (-1);
	if (line[0] != '#')
	{
		if (data->n_ant == 0)
			tr = lem_in_parse_get_ants(line, data);
		else
			tr = lem_in_parse_get_other(line, data, rooms, *file);
	}
	else
	{
		if (ft_strcmp(line, "##start") == 0)
			data->start = data->start == -1 ? 1 : -2;
		else if (ft_strcmp(line, "##end") == 0)
			data->end = data->end == -1 ? 1 : -2;
		if (data->start == -2 || data->end == -2)
			return (ft_msg_int(2, "Abort, double start or end input", -1));
	}
	if (tr < 0)
		return (-1);
	return (1);
}

void			lem_in_delete_last_entry_file(t_file **file, char *line)
{
	t_file	*tmp;
	int		len;
	int		i;

	len = ft_strlen(line);
	tmp = *file;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = 0;
	while (i <= len + 1)
	{
		tmp->buff[tmp->size - i] = '\0';
		i++;
	}
	tmp->size = tmp->size - i + 1;
}
	

int				lem_in_read(t_lem_in_data *data)
{
	char	*line;
	int		tr;
	int		tr2;
	t_file	*file;
	t_parse	*rooms;

	file = NULL;
	line = NULL;
	rooms = NULL;
	tr2 = 1;
	while (tr2 == 1 && (tr = get_next_line(0, &line)) > 0)
	{
		tr2 = lem_in_parse_line(line, data, &file, &rooms);
		if (tr2 < 0)
			lem_in_delete_last_entry_file(&file, line);
		free(line);
		line = NULL;
	}
	lem_in_free_rooms(&rooms);
	if (tr < 0)
		return (ft_msg_int(2, "Abort, failed gnl", -1));
	return (1);
}

t_lem_in_data	*lem_in_parse(int argc, char **argv)
{
	t_lem_in_data	*data;
	int				tr;

	tr = 1;
	if (!(data = (t_lem_in_data *)malloc(sizeof(t_lem_in_data) * 1)))
		return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
	data->n_ant = 0;
	data->n_room = 0;
	data->endroom = 0;
	data->start = -1;
	data->end = -1;
	data->options = 0;
	if (argc > 1)
		tr = lem_in_get_options(argc, argv, data);
	if (tr > 0)
		lem_in_read(data);
	return (data);
}

