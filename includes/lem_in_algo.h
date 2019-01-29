/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:30:26 by erli              #+#    #+#             */
/*   Updated: 2019/01/29 15:01:20 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ALGO_H

# define LEM_IN_ALGO

typedef struct	s_room
{
	char		*name;
	int			id;
	int			x;
	int			y;
}				t_room;

typedef struct	s_lem_in_data
{
	int			n_ant;
	int			start;
	int			end;
	s_room		*anthill;
	char		**matrix;
}


typedef	struct	s_path
{
	int		path_id;
	int		*path;
	int		steps;
}				t_path;

#endif
