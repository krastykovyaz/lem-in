/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:39:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/07/17 23:04:53 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		solve_or_not(t_lemin *stut, int **numb_ant, int i, int solve_ant)
{
	int	z;

	z = stut->check_dist[i] - 1;
	while (z >= 0)
	{
		if (z != stut->check_dist[i] - 1)
		{
			numb_ant[i][z + 1] = numb_ant[i][z];
		}
		if ((z == stut->check_dist[i] - 1) && numb_ant[i][z])
		{
			solve_ant++;
			numb_ant[i][z] = 0;
		}
		if (z == 0)
			numb_ant[i][z] = 0;
		z--;
	}
	return (solve_ant);
}

void	solve(t_lemin *stut, int ant, int **numb_ant, int *nant_path)
{
	int i;
	int j;
	int solve_ant;

	solve_ant = 0;
	j = 0;
	while (solve_ant < ant)
	{
		i = 0;
		while (i < stut->ext_count)
		{
			solve_ant = solve_or_not(stut, numb_ant, i, solve_ant);
			if (stut->ant_way[i] && nant_path[i] <= stut->ant_way[i] \
			&& ++j <= ant)
			{
				numb_ant[i][0] = j;
				nant_path[i]++;
			}
			print_way(stut, i, numb_ant);
			i++;
		}
		if (solve_ant != ant)
			write(1, "\n", 1);
	}
	free(nant_path);
}

void	set_way(t_lemin *stut, int ant)
{
	int i;
	int j;
	int **numb_ant;
	int *nant_path;

	if (!(numb_ant = (int **)malloc(sizeof(int *) * (stut->ext_count))))
		exit(0);
	if (!(nant_path = (int *)malloc(sizeof(int) * (stut->ext_count))))
		exit(0);
	i = 0;
	while (i < stut->ext_count)
	{
		if (stut->ant_way[i])
			nant_path[i] = 1;
		if (!(numb_ant[i] = (int *)malloc(sizeof(int) * stut->check_dist[i])))
			exit(0);
		j = -1;
		while (++j < stut->check_dist[i])
			numb_ant[i][j] = 0;
		i++;
	}
	solve(stut, ant, numb_ant, nant_path);
	free_way(stut, numb_ant);
}
