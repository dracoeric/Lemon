/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:40:35 by erli              #+#    #+#             */
/*   Updated: 2019/02/05 22:29:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# define B_SIZE 16364

typedef	struct	s_room
{
	char	*room;
	int		x;
	int		y;
}				t_room;

typedef	struct	s_file
{
	char			*buf;
	int				size;
	struct s_file	*next;
}				t_file;

typedef	struct	s_data
{
	int		n_room;
	int		n_ant;
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;
	t_room	*rooms;
	char	**matrix;
}				t_data;

#endif
