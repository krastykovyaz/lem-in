/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 10:40:49 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:08:43 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	free_remain(t_lemin *tmp, int i)
{
	int n;

	n = i;
	if (tmp->next != NULL)
	{
		while (n < tmp->enter)
		{
			free(tmp->next[n]);
			n++;
		}
		ft_memdel((void **)&(tmp->next));
	}
	n = i;
	if (tmp->previous != NULL)
	{
		while (n < tmp->enter)
		{
			free(tmp->previous[n]);
			n++;
		}
		ft_memdel((void**)&(tmp->previous));
	}
	ft_memdel((void**)&(tmp->ant_way));
	ft_memdel((void**)&(tmp->check_dist));
	ft_memdel((void**)&tmp);
}

void	free_past(t_lemin *tmp, int i)
{
	int n;

	if (tmp->room_list != NULL)
	{
		ft_lstdel(&(tmp->room_list), &del_content);
		tmp->room_list = NULL;
	}
	n = i;
	if (tmp->visit != NULL)
	{
		while (n < tmp->enter)
		{
			free(tmp->visit[n]);
			n++;
		}
		ft_memdel((void**)&(tmp->visit));
	}
}

void	free_lemin(t_lemin *stut, int i)
{
	t_lemin	*tmp;
	int		n;

	tmp = stut;
	n = i;
	if (tmp->name_room != NULL)
	{
		while (n < tmp->i_room)
		{
			ft_strdel(&(tmp->name_room[n]));
			n++;
		}
		ft_memdel((void **)&(tmp->name_room));
	}
	n = i;
	if (tmp->path != NULL)
	{
		while (n < tmp->i_room)
			free(tmp->path[n++]);
		ft_memdel((void **)&(tmp->path));
	}
	free_past(tmp, i);
	free_remain(tmp, i);
}
