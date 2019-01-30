/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:13:12 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/30 18:56:26 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_parseur.h"

int     lem_in_atoi(char *str, int *d)
{
	int		i;
	long	a;
	long    coeff;

	i = 0;
	a = 0;
	coeff = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		a = str[i] == '+' ? a - coeff * (str[i] - 48) : a;
		coeff = coeff * 10;
		if (a > 2147483648 || (a == 2147483648 && str[0] != '-') || coef > 10000000000)
			return (0);
		i--;
	}
	*d = a;
	return (1);
}

int				lem_in_parse_get_ants(char *line, t_lem_in_data *data)
{
	int	i;

	i = 1;
	if (line[0] != '+' && ft_isdigit(line[0]) == 0)
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	while (line[i] != '\0' && ft_is_digit(line[i]) == 1)
		i++;
	if (line[i] == '\0')
		lem_in_atoi(line, &data->n_ant);
	else
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	if (data->n_ant == 0)
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	return (1);
}

int				lem_in_parse_get_rooms(char *line, t_lem_in_data *data, t_file *rooms, int i)
{
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (line[i] != ' ')
		tr = 0;
	while (tr == 1 && line[i] != '\0' && line[i] == ' ')
		i++;
	while (tr == 1 && line[i] != '\0' && line[i] != ' ' && ft_isdigit(line[i] == 1))
		i++;
	if (line[i] != ' ')
		tr = 0;
	while (tr == 1 && line[i] != '\0' && line[i] != ' ' && ft_isdigit(line[i] == 1))
		i++;
	while (tr == 1 && line[i] != '\0' && line[i] == ' ')
		i++;
	if (tr == 1 && line[i] != '\0')
		tr = 0;
	if (tr == 1)
		tr = lem_in_parse_get_rooms_create(data, rooms);
	if (tr == 0)
		tr = lem_in_parse_check_path(line);
	if (tr < 0)
		return (ft_msg_int(2, "Abort, not a room not a path", -1));
	return (1);
}

int				lem_in_parse_line(char *line, t_lem_in_data *data, t_file **file, t_file **rooms)
{
	int	tr;

	tr = 1;
	if (line[0] == '#')
	{
		if (data->n_ant == 0)
			tr = lem_in_parse_get_ants(line, data)
		else
			tr = lem_in_get_rooms(line, data, rooms, 1)
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
	if (lem_in_fill_file(*line, file) < 0)
		return (-1);
	return (1);
}


int				lem_in_read(t_lem_in_data *data)
{
	int		fd;
	char	*line;
	int		tr;
	t_file	*file;
	t_file	*rooms;

	file = NULL;
	line = NULL;
	rooms = NULL;
	if ((fd = open(0, O_RDONLY)) < 0)
		return (ft_msg_int(2, "Abort, failed open", -1));
	while ((tr = get_next_line(fd, &line)) > 0)
	{
		lem_in_parse_line(line, data, &file, &room);
		free(line);
		line = NULL;
	}
	if (tr < 0)
		return (ft_msg_int(2, "Abort, failed gnl", -1))

}

t_lem_in_data	*lem_in_parse(int argc, char **argv)
{
	t_lem_in_data	*data;
	int				i;

	i = 1;
	if (!(data = (t_lem_in_data *)malloc(sizeof(t_lem_in_data) * 1)))
		return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
	data->n_ant = 0;
	data->n_room = 0;
	data->start = -1;
	data->end = -1;
	while (i < argc)
	{
		//prendre les options
	}
	lem_in_read(data);	

