/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 08:35:03 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 18:55:08 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	fill_path(t_lemin *stut, int n)
{
	int i;
	int j;

	if (n)
	{
		stut->visit[n] = put_zero(stut->i_room);
		j = 0;
		while (j < n)
		{
			i = stut->end;
			while (stut->previous[j][i] != stut->start)
			{
				i = stut->previous[j][i];
				stut->visit[n][i] = 1;
			}
			j++;
		}
	}
}
