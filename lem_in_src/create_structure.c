/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:33:50 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:40:48 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_lemin	*create_lemin(void)
{
	t_lemin	*stut;

	stut = (t_lemin *)malloc(sizeof(t_lemin));
	stut->path = NULL;
	stut->i_room = 0;
	stut->enter = 0;
	stut->ext = 0;
	stut->ext_count = 0;
	stut->name_room = NULL;
	stut->next = NULL;
	stut->room_list = NULL;
	stut->start = -1;
	stut->end = -1;
	stut->steps = 0;
	stut->previous = NULL;
	stut->visit = NULL;
	stut->check_dist = NULL;
	stut->ant_way = NULL;
	return (stut);
}
