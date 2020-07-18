/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:49:13 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 20:35:22 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_way(t_lemin *stut, int i, int **numb_ant)
{
	int d;

	d = stut->check_dist[i] - 1;
	while (d >= 0)
	{
		if (numb_ant[i][d])
		{
			write(1, "L", 1);
			ft_putnbr(numb_ant[i][d]);
			write(1, "-", 1);
			ft_putstr(stut->name_room[stut->next[i][d + 1]]);
			write(1, " ", 1);
			stut->steps++;
		}
		d--;
	}
}
