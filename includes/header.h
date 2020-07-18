/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:04:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 23:04:18 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define FD_SIZE 100
# define BUFF_SIZE 1000

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft.h"

typedef struct	s_lemin
{
	int			**path;
	int			i_room;
	int			enter;
	int			ext;
	int			ext_count;
	char		**name_room;
	int			**visit;
	int			**next;
	int			**previous;
	t_list		*room_list;
	int			start;
	int			end;
	int			*ant_way;
	int			*check_dist;
	int			steps;
}				t_lemin;

int				main(void);
int				get_next_line(const int fd, char **line);
void			read_way(t_lemin *stut, int ant);
t_lemin			*create_lemin(void);
int				follow_line(char **line);
void			free_lemin(t_lemin *stut, int i);
int				add_room(t_lemin *stut, char *line);
void			error(int n, t_lemin *stut);
void			set(t_lemin *stut, int room, int *checker, char *line);
void			tied_room(t_lemin *stut, char *line, int ant);
void			del_content(void *content, size_t content_size);
void			convert(t_lemin *stut);
int				*put_zero(int n);
void			solution(t_lemin *stut);
void			fill_path(t_lemin *stut, int n);
int				*path_tmp(t_lemin *stut, int n);
int				*put_minus(int n);
int				*find_p1(t_lemin *stut, int *tmp, int i);
void			set_next(t_lemin *stut, int n);
void			calc_ant(t_lemin *stut, int ant);
void			set_way(t_lemin *stut, int ant);
void			free_way(t_lemin *stut, int **way);
void			print_way(t_lemin *stut, int i, int **way);

#endif
