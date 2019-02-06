/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:40:35 by erli              #+#    #+#             */
/*   Updated: 2019/02/06 19:50:16 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "mlxadd.h"
# include "libft.h"
# include <stdlib.h>

# define B_SIZE 16364

typedef	struct	s_room
{
	char	*name;
	int		x;
	int		y;
}				t_room;

typedef struct	s_parse
{
	char			*name;
	int				size;
	int				x;
	int				y;
	int				n_buff;
	int				state;
	struct s_parse	*next;
}				t_parse;

typedef	struct	s_file
{
	char			*buff;
	int				size;
	struct s_file	*next;
}				t_file;

typedef	struct	s_visu_data
{
	int		n_ant;
	int		n_room;
	int		endroom;
	int		start;
	int		end;
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;
	int		options;
	t_file	*file;
	t_room	*anthill;
	int		**matrix;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_visu_data;

int				visu_atoi(char *str, int *d);
int				visu_create_anthill_matrix(t_visu_data *data,
					t_parse *rooms);
int				visu_fill_file(char *line, t_file **file);
void			visu_free_data(t_visu_data **data);
void			visu_free_parse(t_parse **rooms);
int				visu_get_options(int argc, char **argv, t_visu_data *data);
t_visu_data		*visu_parse(int argc, char **argv);
int				visu_parse_get_ants(char *line, t_visu_data *data);
int				visu_parse_get_links(char *line, t_visu_data *data,
					int tr1, int tr2);
int				visu_parse_get_rooms(char *line, t_visu_data *data,
					t_parse **rooms, t_file *file);
int				visu_parse_edit_new_room(char *line, t_visu_data *data,
					t_parse *new, int len);
void			visu_print_data(t_visu_data *data);
#endif
