/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:13:12 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/06 18:50:51 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int			visu_parse_get_other(char *line, t_visu_data *data,\
		t_parse **rooms, t_file *file)
{
	int	tr;

	tr = 0;
	if (data->endroom == 0)
		tr = visu_parse_get_rooms(line, data, rooms, file);
	if (tr == 0 && data->endroom == 0)
		tr = visu_create_anthill_matrix(data, *rooms);
	if (tr == 0 && data->endroom == 1)
		tr = visu_parse_get_links(line, data, -1, -1);
	if (tr == 0)
		return (ft_msg_int(2, "Abort, not a pipe, not a room", -1));
	return (tr);
}

static	int			visu_parse_line(char *line, t_visu_data *data,\
		t_file **file, t_parse **rooms)
{
	int	tr;

	tr = 1;
	if (visu_fill_file(line, file) < 0)
		return (-1);
	if (line[0] != '#')
	{
		if (data->n_ant == 0)
			tr = visu_parse_get_ants(line, data);
		else
			tr = visu_parse_get_other(line, data, rooms, *file);
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
		return (tr);
	return (1);
}

static	void		visu_delete_last_entry_file(t_file **file, char *line)
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

static	int			visu_read(t_visu_data *data)
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
		tr2 = visu_parse_line(line, data, &file, &rooms);
		if (tr2 < 0)
			visu_delete_last_entry_file(&file, line);
		free(line);
		line = NULL;
	}
	data->file = file;
	visu_free_parse(&rooms);
	if (tr < 0)
		return (ft_msg_int(2, "Abort, failed gnl", -1));
	if (tr2 == -2)
		return (-1);
	return (1);
}

t_visu_data			*visu_parse(int argc, char **argv)
{
	t_visu_data	*data;
	int			tr;

	tr = 1;
	if (!(data = (t_visu_data *)malloc(sizeof(t_visu_data) * 1)))
		return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
	data->n_ant = 0;
	data->n_room = 0;
	data->endroom = 0;
	data->start = -1;
	data->end = -1;
	data->options = 0;
	data->anthill = NULL;
	data->matrix = NULL;
	if (argc > 1)
		tr = visu_get_options(argc, argv, data);
	if (tr > 0)
		tr = visu_read(data);
	if (tr < 0)
		visu_free_data(&data);
	return (data);
}