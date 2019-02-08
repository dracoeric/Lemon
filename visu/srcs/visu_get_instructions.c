/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:17:56 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 13:47:52 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int		visu_get_old_instructions(t_visu_data *data)
{
	char *line;

	if (VI_PLAY_BACKWARD(data->play_param) && data->cursor < HIST_SIZE - 1)
	{
		line = data->history[data->cursor + 1];
		data->cursor += (line == NULL ? 0 : 1);
		return (visu_do_instructions(data, line));
	}
	else if (VI_PLAY_FORWARD(data->play_param))
	{
		line = data->history[(data->cursor)--];
		return (visu_do_instructions(data, line));
	}
	return (1);
}

static	void	visu_move_down(char **history)
{
	int i;

	i = HIST_SIZE - 1;
	while (i > 0)
	{
		history[i] = history[i - 1];
		i--;
	}
}

static	int		visu_get_new_instructions(t_visu_data *data)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	if (ret <= 0)
		return (ret == 0 ? 0 : ft_msg_int(2, "Failed GNL\n", -1));
	if (visu_check_instructions(data, line) < 0)
		return (-1);
	free(data->history[HIST_SIZE - 1]);
	visu_move_down(data->history);
	data->history[0] = line;
	return (visu_do_instructions(data, line));
}

int				visu_get_instructions(t_visu_data *data)
{
	int		ret;

	ret = 1;
	if (!(data->cursor == -1 && VI_PLAY_FORWARD(data->play_param)))
		ret = visu_get_old_instructions(data);
	else
		ret = visu_get_new_instructions(data);
	return (ret);
}
