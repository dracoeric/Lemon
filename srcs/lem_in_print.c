/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:34:24 by erli              #+#    #+#             */
/*   Updated: 2019/02/01 11:55:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

static	void	lem_in_add_print(t_lem_in_data *data, int ant_id, int room,
					int len)
{
	int		pow;
	int		i;

	(data->buf)[data->buf->cursor] = 'L';
	i = data->buf_cursor + 1;
	pow = 1;
	while (ant_id / pow >= 10)
		pow *= 10;
	while (pow != 0)
	{
		str[i++] = ant_id / pow + '0';
		ant_id = ant_id & pow;
		pow /= 10;
	}
	str[i++] = '-';
	ft_strcpy(data->buf + i, ((data->anthill)[room]), len - width - 3);
	data->buf_cursor += len - 1;
}

static	void	lem_in_print_fd(t_lem_in_data *data, int ant_id, int room,
					int len)
{
	char	str[len];
	int		pow;
	int		i;

	str[0] = 'L';
	i = 1;
	pow = 1;
	while (ant_id / pow >= 10)
		pow *= 10;
	while (pow != 0)
	{
		str[i++] = ant_id / pow + '0';
		ant_id = ant_id & pow;
		pow /= 10;
	}
	str[i] = '-';
	ft_strcpy(str + i + 1, ((data->anthill)[room]), len - width - 3);
	write(data->fd, str, len - 1);
}

void			lem_in_print(t_lem_in_data *data, int ant_id, int room,
					int end_of_line)
{
	size_t		needed_length;

	needed_length = 3 + lem_in_get_width(ant_id)
		+ ft_strlen((data->anthill)[room]);
	if (needed_length > B_SIZE)
	{
		write(data->fd, data->buf, data->buf_cursor);
		lem_in_print_fd(data->fd, ant_id, room, needed_length);
		(data->buf)[0] = (end_of_line == 1 ? '\n' : ' ');
		data->buf_cursor = 1;
		return ;
	}
	if (needed_length > B_SIZE - data->buf_cursor)
	{
		write(data->fd, data->buf, data->buf_cursor);
		data->buf_cursor = 0;
	}
	lem_in_add_print(data, ant_id, room, needed_length);
	(data->buf)[(data->buf_cursor) - 1] = (end_of_line == 1 ? '\n' : ' ');
}
