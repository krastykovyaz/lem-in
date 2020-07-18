/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:41:11 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:53:58 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		calc_way(t_lemin *stut, int n)
{
	int i;
	int j;

	i = 1;
	j = stut->end;
	while (stut->previous[n][j] != stut->start)
	{
		i++;
		j = stut->previous[n][j];
	}
	return (i);
}

void	set_next(t_lemin *stut, int n)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	while (i < n)
	{
		l = calc_way(stut, i);
		k = stut->end;
		j = l;
		stut->next[i][l] = stut->end;
		while (stut->previous[i][k] != stut->start)
		{
			j -= 1;
			stut->next[i][j] = stut->previous[i][k];
			k = stut->previous[i][k];
		}
		stut->next[i][0] = stut->start;
		i++;
	}
	write(1, "\n", 1);
}
