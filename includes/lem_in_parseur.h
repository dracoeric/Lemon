/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parseur.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:16:11 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/30 13:20:08 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_PARSEUR_H

# define LEM_IN_PARSEUR_H
# define B_SIZE 10000
typedef	struct	s_file
{
	char			*buff;
	int				size;
	struct s_file	*next;
}				t_file;

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
	int			n_room;
	char		**anthill;
	char		**matrix;
}				t_lem_in_data;


typedef	struct	s_path
{
	int		path_id;
	int		*path;
	int		steps;
}				t_path;

t_lem_in_data	*lem_in_parse(int argc, char **argv);
int				lem_in_fill_file(char *file, t_file **file);

#endif
