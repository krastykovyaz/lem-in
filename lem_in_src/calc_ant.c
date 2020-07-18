/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:28:23 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 16:15:18 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		distance_calc(t_lemin *stut, int n)
{
	int i;
	int k;

	i = 1;
	k = stut->end;
	while (stut->previous[n][k] != stut->start)
	{
		i++;
		k = stut->previous[n][k];
	}
	return (i);
}

void	prepair_ant(t_lemin *stut)
{
	int i;

	if (!(stut->ant_way = (int *)malloc(sizeof(int) * stut->ext_count)))
		exit(0);
	if (!(stut->check_dist = (int *)malloc(sizeof(int) * stut->ext_count)))
		exit(0);
	i = 0;
	while (i < stut->ext_count)
	{
		stut->ant_way[i] = 0;
		stut->check_dist[i] = distance_calc(stut, i);
		i++;
	}
}

void	calc_ant(t_lemin *stut, int ant)
{
	int i;
	int j;
	int k;
	int size;

	prepair_ant(stut);
	k = ant;
	while (k)
	{
		i = 0;
		size = stut->ant_way[0] + stut->check_dist[0];
		j = 0;
		while (i < stut->ext_count)
		{
			if (stut->ant_way[i] + stut->check_dist[i] < size)
				j = i;
			i++;
		}
		stut->ant_way[j]++;
		k--;
	}
}
