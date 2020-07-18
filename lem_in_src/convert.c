/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:56:05 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 18:53:20 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	convert(t_lemin *stut)
{
	t_lemin	*conv_stut;
	t_list	*l;
	int		i;

	i = 0;
	conv_stut = stut;
	if (!(conv_stut->path = (int **)malloc(sizeof(int **) * conv_stut->i_room)))
		exit(0);
	if (!(conv_stut->name_room = (char **)malloc(sizeof(char **) * \
	(1 + conv_stut->i_room))))
		exit(0);
	l = conv_stut->room_list;
	while (i < conv_stut->i_room)
	{
		conv_stut->path[i] = put_zero(conv_stut->i_room);
		conv_stut->name_room[i] = ft_strdup((char *)l->content);
		l = l->next;
		i++;
	}
	conv_stut->name_room[i] = NULL;
	ft_lstdel(&(conv_stut->room_list), &del_content);
	conv_stut->room_list = NULL;
	conv_stut->start = conv_stut->i_room - (1 + conv_stut->start);
	conv_stut->end = conv_stut->i_room - (1 + conv_stut->end);
}
