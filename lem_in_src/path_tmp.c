/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 08:55:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:33:44 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	send_zero(t_lemin *stut, int n)
{
	stut->previous[n] = put_zero(stut->i_room);
	stut->next[n] = put_zero(stut->i_room);
	if (!n)
		stut->visit[n] = put_zero(stut->i_room);
	stut->previous[n][stut->start] = stut->start;
	if (stut->start == stut->end)
		write(1, "start=end\n", 10);
	stut->visit[n][stut->start] = 1;
}

int		*path_tmp(t_lemin *stut, int n)
{
	int i;
	int j;
	int *tmp;

	j = 0;
	i = 0;
	tmp = put_minus(stut->i_room);
	send_zero(stut, n);
	while (i < stut->i_room)
	{
		if (stut->path[stut->start][i] && !(stut->visit[n][i]))
		{
			stut->previous[n][i] = stut->start;
			if (i != stut->end && (tmp[j] = i) >= 0)
			{
				stut->visit[n][i] = 1;
				j++;
			}
			else
				break ;
		}
		i++;
	}
	return (tmp);
}
