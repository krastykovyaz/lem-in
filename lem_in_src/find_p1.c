/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 10:18:35 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 19:21:39 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	end_or_not(t_lemin *stut, int k, int *temp2, int i)
{
	int l;

	l = 0;
	if (k != stut->end && (temp2[l] = k) >= 0)
	{
		stut->visit[i][k] = 1;
		l++;
	}
	else
	{
		stut->ext_count++;
	}
}

int		*find_exit(t_lemin *stut, int *tmp, int i)
{
	int k;
	int m;
	int *temp2;

	temp2 = put_minus(stut->i_room);
	m = 0;
	while (tmp[m] != -1 && stut->ext_count == i)
	{
		k = 0;
		while (k < stut->i_room && stut->ext_count == i)
		{
			if (stut->path[tmp[m]][k] && !(stut->visit[i][k]))
			{
				stut->previous[i][k] = tmp[m];
				end_or_not(stut, k, temp2, i);
			}
			k++;
		}
		m++;
	}
	return (temp2);
}

int		*find_p1(t_lemin *stut, int *tmp, int i)
{
	int *temp2;

	while (stut->ext_count == i)
	{
		temp2 = find_exit(stut, tmp, i);
		ft_memdel((void **)&tmp);
		tmp = temp2;
		if (stut->ext_count == i && tmp[0] == -1)
		{
			stut->ext = stut->ext_count;
			error((stut->ext == 0), stut);
			break ;
		}
	}
	return (tmp);
}
